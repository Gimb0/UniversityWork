#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#define BUF_LEN 48

int stringReverse(char *oriString, char *revString) 
{
	int len = strlen(oriString);
	for (int i = 0; i < len; i++) 
	{
		revString[i] = oriString[len-i-1];
	}
	revString[len] = '\0';

	return len;
}

int main(int argc, char *argv[]) 
{
	int ssd;					
	struct sockaddr_in server;	
	struct sockaddr_in client;	
	int client_len;				
	short echo_port;			
	int max_iterations;			
	int outCnt, inCnt;			
	int recvCnt, i;				
	char clientString[BUF_LEN];	
	char svrRevString[BUF_LEN];

	int retCode;

	if (argc != 3) 
	{
		fprintf(stderr, "Usage: %s Port Max_iterations\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	echo_port = atoi(argv[1]);
	max_iterations = atoi(argv[2]);

	ssd = socket(PF_INET, SOCK_DGRAM, 17);
	if (ssd < 0) 
	{
		perror("Creating socket");
		exit(EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(echo_port);

	retCode = bind(ssd, (struct sockaddr *)&server, sizeof(server));
	if (retCode < 0) 
	{
		perror("Binding socket");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < max_iterations; i++) 
	{
		fprintf(stderr, "Iteration %d of %d. Waiting for client...\n", 
				i+1, max_iterations);
		client_len = sizeof(client);

		// Make the server wait till it receives input from client
		inCnt = recvfrom(ssd, clientString, BUF_LEN, 0, 
				(struct sockaddr *) &client, (socklen_t *) &client_len);

		if (inCnt < 0) 
		{
			perror("Receiving input from client");
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "Message received is %d bytes long\n", inCnt);
		fprintf(stderr, "Message received is \"%s\"\n", clientString);

		recvCnt = stringReverse(clientString, svrRevString);

		fprintf(stderr, "Reversed string is %d bytes long\n", recvCnt);
		fprintf(stderr, "Reversed string is \"%s\"\n", svrRevString);

		outCnt = sendto(ssd, svrRevString, recvCnt+1, 0, 
				(const struct sockaddr*) &client, sizeof(client));

		if (outCnt < 0) 
		{
			perror("Sending reversed message back to client");
			exit(EXIT_FAILURE);
		}

		fprintf(stderr, "Client request now serviced reply sent.\n");
	}

	close(ssd);

	fprintf(stderr, "Server shut down!\n");

	return 0;
}
