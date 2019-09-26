#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_LEN 2048

/*
 * Establish connection to server
 * Returning socket
*/ 
int establish_connection(char host_name[], char port[]) 
{
	int csd;
	struct sockaddr_in server;
	struct hostent *server_host;
	int server_len;
	int string_size;
	short server_port;
	int in_cnt, out_cnt;

	server_host = gethostbyname(host_name);
	server_port = atoi(port);
	
	if (server_host == NULL) 
	{
		fprintf(stderr, "While calling gethostbyname()\n");
		exit(EXIT_FAILURE);
	}


	csd = socket(PF_INET, SOCK_STREAM, 0);
	if (csd < 0) 
	{
		fprintf(stderr, "Creating socket\n");
		exit(EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	memcpy(&server.sin_addr.s_addr, server_host->h_addr_list[0], 
			server_host->h_length);
	server.sin_port = htons(server_port);

	if (connect(csd, (struct sockaddr *)&server, sizeof(server)) != 0) 
	{
		perror("Connecting to server");
		exit(EXIT_FAILURE);
	}

	return csd;
}

/*
 * Send get or head request to server
 * Requires: (int) socket descriptor, (char) request type
 * Returns nothing
*/
void send_request(int csd, char req_type[])
{
	char request[256];
	char response[BUF_LEN];
	int len = 0;
	char *subStr;
	
	if (strcmp(req_type, "head") == 0)
	{
		strcpy(request, "HEAD / HTTP1.1\r\n\r\n");
	} else if (strcmp(req_type, "get") == 0)
	{
		strcpy(request, "GET / HTTP1.1\r\n\r\n");
	} else {
		fprintf(stderr, "Bad type");
		exit(EXIT_FAILURE);
	}

	if (write(csd, request, sizeof(request)) < 1)
	{
		perror("Writing to socket");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Sent:\n%s", request);

	if ((len = read(csd, response, BUF_LEN)) < 0)
	{
		perror("Reading from socket");
		exit(EXIT_FAILURE);
	} else if (len == 0)
	{
		fprintf(stderr, "Connection closed by host\n");
	} 
	else 
	{
		fprintf(stderr, "Received:\n");
		fprintf(stderr, "%s\n", subStr);
	}

}

int main(int argc, char *argv[]) 
{
	int csd;

	if (argc != 4)
	{
		fprintf(stderr, "Usage: %s ServerIP ServerPORT" 
			" HTTP_request_type\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Establishing connection to %s\n", argv[1]);
	csd = establish_connection(argv[1], argv[2]);

	fprintf(stderr, "Sending request to %s\n", argv[1]);
	send_request(csd, argv[3]);

	close(csd);
}
