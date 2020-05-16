/*
 * IPv6 Server created by Bradley Semlitzky
 * Server sends simple text back
*/ 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define SERVER_TCP_PORT 1337

#define BUF_LEN 512

void manage_connection(int in, int out);
void handle_sigchild(int sig_num);
void handle_sigexit(int sig_num);
static int rsd_socket;

int main()
{
	int rsd; /* rendezvous socket */
	int esd; /* ephemeral socket */
	int error_code;
	int pid;
	int client_len;
	struct sockaddr_in6 client, server;
	struct hostent *client_details;
	struct sigaction cldsig, mainsig;

	fprintf(stderr, "M: Server is starting...\n");

	/* Stop zombie processes using signals */
	cldsig.sa_handler = handle_sigchild;
	sigfillset(&cldsig.sa_mask);
	cldsig.sa_flags = SA_RESTART | SA_NOCLDSTOP;
	sigaction(SIGCHLD, &cldsig, NULL);

	/* Close main socket on SIGINT */
	mainsig.sa_handler = handle_sigexit;
	sigfillset(&mainsig.sa_mask);
	mainsig.sa_flags = SA_RESTART;
	sigaction(SIGINT, &mainsig, NULL);

	/* Create initial socket */
	rsd = socket(PF_INET6, SOCK_STREAM, 0);
	if (rsd < 0)
	{
		perror("Creating the rendezvous socket");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "M:\trsd = %d\n", rsd);

	/*
	 * Using a struct to set the networking details
	 * of the server instead of specifying the address
	 * and port seperately in the socket system calls
	*/ 
	memset(&server, 0, sizeof(server));
	server.sin6_family = AF_INET6;
	server.sin6_addr = in6addr_any;
	server.sin6_port = htons(SERVER_TCP_PORT);

	/*
	 * Bind socket to host and listen for incoming connections
	*/
	if ((error_code = bind(rsd, (struct sockaddr*)&server, 
			       sizeof(server)) ) < 0)
	{
		perror("M: While binding socket");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "M:\tBound\n");

	if ((error_code = listen(rsd, 5)) < 0)
	{
		perror("M: While establishing listening queue");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "M:\tListening...\n");
	fprintf(stderr, "M: ...setup complete. Ready for connections\n");

	/* Main Server Loop */
	for (;;)
	{
		/* Create new socket for first connection */
		client_len = sizeof(client);
		if ((esd = accept(rsd, (struct sockaddr*) &client, 
		    (socklen_t *) &client_len)) < 0)
		{
			perror("M: While accepting connections");
			exit(EXIT_FAILURE);
		}

		client_details = gethostbyname((void *) &client.sin6_addr);

		if (client_details == NULL)
		{
			herror("M: While resolving client address");
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "M: Accepted a connection from %s on port %d"\
			" with esd = %d\n", client_details->h_name,
			ntohs(client.sin6_port), esd);

		/*
		 * Create a new process for each connection. Child
		 * process runs a client handling function. Parent
		 * cleans up variables and restarts loop
		*/
		if ((pid = fork()) == 0)
		{
			close(rsd);
			manage_connection(esd, esd);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(rsd);
			fprintf(stderr, "M: Process %d will service this\n",
				pid);
		}
	}
	close(rsd);
}

void manage_connection(int in, int out)
{
	int read_count;
	char input_buffer[BUF_LEN], output_buffer[BUF_LEN], hostname[40];
	char prefix[100];

	gethostbyname2(hostname, 40);

	sprintf(prefix, "\tC %d:", getpid());
	fprintf(stderr, "\n%s starting up\n", prefix);
	sprintf(output_buffer, "\n\nConnected to Gumbis simple server...\n" \
		"Host: %s\n\nEnter X to exit.\nOtherwise enter the secret " \
		"number: ", hostname);

	write(out, output_buffer, strlen(output_buffer));
	
	if ((read_count = read(out, input_buffer, BUF_LEN)) < 1)
	{
		perror("Reading from socket");
		exit(EXIT_FAILURE);
	}

	if (strncmp(input_buffer, "1337", 4) == 0 || 
	    strncmp(input_buffer, "31337", 5) == 0)
	{
		sprintf(output_buffer, "\n*** Authorization Successful ***\n" \
			"Welcome\n");
	}
	else
	{
		sprintf(output_buffer, "\n*** Authorization Failed ***\n" \
			"Goodbye\n");
	}
	write(out, output_buffer, strlen(output_buffer));

	close(in);
	close(out);
}

void handle_sigchild(int sig_num)
{
	pid_t cld;

	while (0 < waitpid(-1, NULL, WNOHANG));
}

void handle_sigexit(int sig_num)
{
	close(rsd_socket);
	exit(EXIT_SUCCESS);
}
