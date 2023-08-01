#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT_ID 8800
#define SIZE 100

int main(int argc, char* argv[])
{
	int client_fd;
	struct sockaddr_in server_addr;
	int addr_len = sizeof(struct sockaddr);
	char buffer[SIZE];
	
	if(argc != 2)
	{
		printf("Usage: ./client <ip_addr>\n");
		exit(1);
	}

	// 1. socket()
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	// 2. connect()
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_ID);
	// server_addr.sin_addr = inet_addr(argv[1]);
	if(inet_aton(argv[1], &server_addr.sin_addr) == 0)
	{
		printf("Invalid ip address!\n");
		exit(1);
	}
	connect(client_fd, (const struct sockaddr*)&server_addr, addr_len);
	// 3. recv()
	recv(client_fd, buffer, SIZE, 0);
	printf("Client received from server: %s\n", buffer);
	// 4. close()
	close(client_fd);

	return 0;
}
