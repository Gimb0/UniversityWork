#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_LEN 48

int main(int argc, char *argv[]) 
{
	int csd;
	struct sockaddr_in server;
	struct hostent *server_host;
	int server_len;
	int string_size;
	short server_port;
	int in_cnt, out_cnt;
	char send_string[BUF_LEN];
	char receive_string[BUF_LEN];

	if (argc != 4) 
	{
		fprintf(stderr, "Usage: %s ServerIP ServerPORT Message\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	server_host = gethostbyname(argv[1]);
	if (server_host == NULL) 
	{
		fprintf(stderr, "While calling gethostbyname()\n");
		exit(EXIT_FAILURE);
	}

	server_port = atoi(argv[2]);
	strncpy(send_string, argv[3], BUF_LEN);

	csd = socket(PF_INET, SOCK_DGRAM, 0);
	if (csd < 0) 
	{
		fprintf(stderr, "Creating socket\n");
		exit(EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	memcpy(&server.sin_addr.s_addr, server_host->h_addr_list[0], 
			server_host->h_length);
	server.sin_port = htons(server_port);

	string_size = strlen(send_string) + 1;

	out_cnt = sendto(csd, send_string, string_size, 0, 
			(struct sockaddr *)&server, sizeof(server));
	if (out_cnt < 0) 
	{
		perror("Calling sendto()");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "You have sent \"%s\"\n", send_string);
	fprintf(stderr, "Now waiting for a response using recvfrom()\n");

	server_len = sizeof(server);
	in_cnt = recvfrom(csd, receive_string, BUF_LEN, 0, 
			(struct sockaddr *)&server, (socklen_t *)&server_len);
	if (in_cnt < 0) 
	{
		perror("Calling recvfrom()");
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Server responded with \"%s\"\n", receive_string);

	close(csd);
}
