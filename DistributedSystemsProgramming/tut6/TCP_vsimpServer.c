#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>

#define SERVER_TCP_PORT 1337

#define BUF_LEN 512
#define COM_BUF_LEN 32

void manage_connection(int, int);
int server_processing(char *instr, char *outstr);
void handle_sigcld(int);

int main()
{
	int rsd;
	int esd;
	int ec;
	int client_len;
	int pid;
	struct sockaddr_in client,server;
	struct hostent *client_details;
	struct sigaction cldsig;

	fprintf(stderr, "M: The DSAP example server is starting up...\n");

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
	if ((ec = bind(rsd, (struct sockaddr*)&server), sizeof(server)) < 0)
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

		client_details = gethostbyname((void *) &client.sin_addr.s_addr
				, 4, AF_INET);

		if (client_details == NULL)
		{
			herror("M: While resolving client address");
			exit(EXIT_FAILRE);
		}

		fprintf(stderr, "M: Accepted a connection from %s on port %d 
				with esd = %d\n", client_details->h_name,
				ntohs(client.sin_port), essd);
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
	char inbuf[BUF_LEN], outbuf[BUF_LEN], in_data[COM_BUF_LEN], 
	     hostname[40];
	char prefix[100];
	char end_of_data = '&';
	int i;
	int revcnt;
	char revbuf[BUF_LEN];

	gethostname(hostname, 40);

	sprintf(prefix, "\tC %d:", getpid());
	fprintf(stderr, "\n%s starting up\n", prefix);
	sprintf(outbuf, "\n\nConnected to Gumbis simple server...\nHost: %s"\
			"\n\nEnter X to exit.\nOtherwise enter the secret "\
			"password: ", hostname);

	write(out, outbuf, strlen(outbuf));

	while (1)
	{
		bc = 0;
		while (1)
		{
			rc = read(in, in_data, COM_BUF_LEN);
			if (rc>0)
			{
				if ((rc+bc) > BUF_LEN)
				{
					fprintf(stderr, "\n%sReceived buffer"\
						"size exceeded!\n", prefix);
					close(in);
					exit(EXIT_SUCCESS);
				}
				fprintf(stderr, "%sHave read in:\n", prefix);
				for(i=0; i<rc; i++)
					fprintf(stderr, "%s%d\t%c\n", prefix, 
						in_data[i], in_data[i]);
				memcpy(&inbuf[bc], in_data, rc);
				bc+=rc;

				if (in_data[rc-1] == end_of_data) break;
			}
			else if (rc == 0)
			{
				fprintf(stderr, "\n%sCLient has closed the"\
						"connection so should we\n"\
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
		}
		inbuf[bc-2] = '\0';
		if (inbuf[0] == 'X') break;

		if (server_processing(inbuf))
		{
			sprintf(outbuf, "Server received %d bytes, with a "\
					"password attempt of %s", 
					strlen(inbuf), inbuf);
			write(out, "You guessed the password!!! :)\n", 32);
		}
		else
		{
			sprintf(outbuf, "Server received %d bytes, with a "\
					"password attempt of %s", 
					strlen(inbuf), inbuf);
			write(out, "You did not guess password :(\n", 32);
		}
	}	
}

/*
 * Compare input with password
 * Return true if match, false if no match
*/ 
bool server_processing(char *in_str)
{
	char password[9];
	strncpy(password, "password\0", 9);

	if ((strncmp(in_str, password, strlen(password))) == 0)
	{
		return true;
	}
	else
	{
		return false; 
	}
}

void handle_sigcld(int signo)
{
	pid_t cld;

	while(0 < waitpid(-1, NULL, WNOHANG));
}
