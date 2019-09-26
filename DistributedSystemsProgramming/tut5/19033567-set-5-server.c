#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>

#define SERVER_TCP_PORT 1337

#define BUF_LEN 512

void manage_connection(int, int);
char* server_processing(char *instr);
void handle_sigcld(int);

int main()
{
	int rsd; /* rendezvous socket */
	int esd; /* ephemeral socket */
	int ec;
	int client_len;
	int pid;
	int enable = 1;
	struct sockaddr_in client, server;
	struct hostent *client_details;
	struct sigaction cldsig;

	fprintf(stderr, "M: HTTP server is starting up...\n");

	/*
	 * Stop zombie child processes using signals
	*/
	cldsig.sa_handler = handle_sigcld;
	sigfillset(&cldsig.sa_mask);
	cldsig.sa_flags = SA_RESTART | SA_NOCLDSTOP;
	sigaction(SIGCHLD, &cldsig, NULL);

	/*
	 * Create initial socket and error check it
	*/
	rsd = socket(PF_INET, SOCK_STREAM, 0);
	if (rsd < 0)
	{
		perror("Creating the rendezvous socket");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "M:\trsd=%d\n",rsd);

	if ((setsockopt(rsd, SOL_SOCKET, SO_REUSEADDR, &enable,
			sizeof(int))) < 0)
	{
		perror("Setting socket options");
		exit(EXIT_FAILURE);
	}

	/*
	 * Using a struct to set the networking details
	 * of the server instead of specifying the address
	 * and port seperately in the socket system calls
	*/
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(SERVER_TCP_PORT);

	/*
	 * Bind socket to a name/address and then listen
	 * for any incoming connections to that address
	*/
	if ((ec = bind(rsd, (struct sockaddr*)&server, sizeof(server))) < 0)
	{
		perror("M: While binding socket");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "M:\tBound\n");

	if((ec = listen(rsd, 5)) < 0 )
	{
		perror("M: While setting the listen queue up");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "M:\tListening...\n");

	fprintf(stderr, "M: ...setup complete, ready for connections\n");

	/*
	 * Main Server loop
	*/
	for (;;)
	{
		/*
		 * Create a new socket for the first connection to
		 * the rendezvous socket using accept() sys call.
		*/
		client_len = sizeof(client);
		if ((esd = accept(rsd, (struct sockaddr*) &client,
				 (socklen_t *) &client_len)) < 0)
		{
			perror("M: While accepting connection");
			exit(EXIT_FAILURE);
		}
		fprintf(stderr,"client addr is: %d\n",client.sin_addr.s_addr);
		client_details = gethostbyaddr((void *)&client.sin_addr.s_addr
					       , 4, AF_INET);

		if (client_details == NULL)
		{
			herror("M: While resolving client address");
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "M: Accepted a connection from %s on port %d"\
				" with esd = %d\n", client_details->h_name,
				ntohs(client.sin_port), esd);
		/*
		 * Create a new processes for each connection. Child
		 * process runs a client handling function. Parent
		 * cleans up variable and restarts loop
		*/
		if ((pid = fork()) == 0)
		{
			close(rsd);
			manage_connection(esd, esd);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(esd);
			fprintf(stderr, "M: Process: %d with service this.\n",
				pid);
		}
	}
	close(rsd);
}

void manage_connection(int in, int out)
{
	int rc, bc;
	char inbuf[BUF_LEN], hostname[40];
	char * outbuf;
	char prefix[100];
	char end_of_data = '\n';
	int i;
	int revcnt;
	char revbuf[BUF_LEN];

	gethostname(hostname, 40);

	sprintf(prefix, "\tC %d:", getpid());
	fprintf(stderr, "\n%s starting up\n", prefix);

	bc = 0;
	rc = read(in, inbuf, BUF_LEN);
	if (rc>0)
	{
		if ((rc+bc) > BUF_LEN)
		{
			fprintf(stderr, "\n%sReceived buffer"\
				" size exceeded!\n", prefix);
			close(in);
			exit(EXIT_SUCCESS);
		}
		/*
		fprintf(stderr, "%sHave read in:\n", prefix);
		for(i=0; i<rc; i++)
			fprintf(stderr, "%s%x\t%c\n", prefix,
				inbuf[i], inbuf[i]);
		*/
		bc+=rc;
	}
	else if (rc == 0)
	{
		fprintf(stderr, "\n%sCLient has closed the "\
				"connection, so should we.\n"\
				, prefix);
		close(in);
		exit(EXIT_FAILURE);
	}
	else
	{
		sprintf(prefix, "\tC %d: While reading from"\
				" connection", getpid());
		perror(prefix);
		close(in);
		exit(EXIT_FAILURE);
	}

	outbuf = server_processing(inbuf);
	write(out, outbuf, strlen(outbuf));
	free(outbuf);	
}

/*
 * Build response based on HTTP request
*/
char * server_processing(char *in_str)
{
	fprintf(stderr, "in_str:\n%s\n", in_str);

	char* response = malloc(BUF_LEN);
	char text[] = "Little Bo-Peep has lost her sheep, \n" \
		      "and doesn't know where to find them; \n" \
		      "leave them alone, And they'll come home, \n" \
		      "wagging (bringing) their tails behind them. \n" \
		      "Little Bo-Peep fell fast asleep, \n" \
		      "and dreamt she heard them bleating; \n" \
		      "but when she awoke, she found it a joke, \n" \
		      "for they were still a-fleeting. \n" \
		      "Then up she took her little crook, \n" \
		      "determined for to find them; \n" \
		      "she found them indeed, but it made her heart bleed, \n" \
		      "for they'd left their tails behind them. \n" \
		      "It happened one day, as Bo-Peep did stray \n" \
		      "into a meadow hard by, \n" \
		      "there she espied their tails side by side, \n" \
		      "all hung on a tree to dry. \n" \
		      "She heaved a sigh and wiped her eye, \n" \
		      "and over the hillocks went rambling, \n" \
		      "and tried what she could, as a shepherdess should, \n" \
		      "to tack each again to its lambkin. \n";
	int size = 0;
	char size1[6];
	int i;
	int j = 0;
	int num_of_lines;
	char lines[1024];
	char* character = text;

	srand((unsigned) time(0));

	if (strncmp(in_str, "HEAD", 4) == 0) /* Check if HTTP HEAD request */ 
	{
		fprintf(stderr, "Received HEAD request from client\n");
		strcpy(response, "HTTP/1.1 200 OK\r\n" \
		       "Content-Type: text/plain\r\n" \
		       "Content Length: ");
		size = strlen(response);
		sprintf(size1, "%d", size);
		size += strlen(size1) + 4;
		sprintf(size1, "%d", size);
		strcat(response, size1);
	}
	else if (strncmp(in_str, "GET", 3) == 0)/* Check if HTTP GET Request */ 
	{
		fprintf(stderr, "Received GET request from client\n");
		/* Check if GET request requested root document */
		if (strncmp(in_str, "GET / HTTP/1.1", 14) == 0) 
		{
			fprintf(stderr, "Client requested root document\n");
			strcpy(response, "HTTP/1.1 200 OK\r\n" \
			       "Content-Type: text/plain\r\n" \
			       "Content Length: ");
			num_of_lines = rand() % 20;
			/* Get a random number of lines from text data */
			for (i = 0; i < sizeof(text); i++)
			{
				if (*character == '\n')
				{
					j++;
				}
				if (j == num_of_lines)
				{
					break;
				} 
				else 
				{
					lines[i] = *character;
				}
				character += 1;
			}
			/* Put together headers and body */
			size = strlen(response) + strlen(lines);
			sprintf(size1, "%d", size);
			size += strlen(size1);
			sprintf(size1, "%d", size);
			strcat(response, size1);
			strcat(response, "\r\n\r\n");
			strcat(response, lines);
		}
		else /* Check if client request file other than root document*/
		{
			fprintf(stderr, "Client requested some weird shit we " \
				"don't have\n" );
			strcpy(response, "HTTP/1.1 404 Not Found\r\n" \
			       "Content-Type: text/plain\r\n" \
			       "Content-Length: ");
			size = strlen(response);
			sprintf(size1, "%d", size);
			size += strlen(size1);
			sprintf(size1, "%d", size);
			strcat(response, size1);
		}
	}
	else /* Build response for HTTP requests other than GET and HEAD */
	{
		fprintf(stderr, "Client sent weird HTTP request\n");
		strcpy(response, "HTTP/1.1 501 Not Implemented\r\n" \
		       "Content-Type: text/plain\r\n"\
		       "Content-Length: ");
		strcpy(lines, "Connection: close");
		size = strlen(response);
		sprintf(size1, "%d", size);
		size += strlen(size1) + 4;
		sprintf(size1, "%d", size);
		strcat(response, size1);
	}
	strcat(response, "\r\n\r\n");

	return response;
}

void handle_sigcld(int signo)
{
	pid_t cld;

	while(0 < waitpid(-1, NULL, WNOHANG));
	}
