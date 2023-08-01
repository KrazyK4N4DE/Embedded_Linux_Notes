#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define PORT_ID 8800
#define BACKLOG 10
#define SIZE 100

int client_fd;
struct sockaddr_in client_addr;
char welcome[SIZE] = "Welcome to conect to the server!";

void* thread_function(void* arg);

int main(void)
{
	int server_fd;
	struct sockaddr_in server_addr;
	int addr_len = sizeof(struct sockaddr);
	pthread_t pthread;
		
	// 1. socket()
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	// 2. bind()
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_ID);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bind(server_fd, (const struct sockaddr*)&server_addr, addr_len);
	// 3. listen()
	listen(server_fd, BACKLOG);
	
	while(1)
	{
		printf("Server is waiting for client to connect...\n");
		// 4. accept()
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
		// 5. Create pthread
		pthread_create(&pthread, NULL, thread_function, NULL);
	}
	close(server_fd);

	return 0;
}

void* thread_function(void* arg)
{
	printf("Client address = %s\n", inet_ntoa(client_addr.sin_addr));
	send(client_fd, welcome, SIZE, 0);
	printf("Disconnect the client request.\n");
	close(client_fd);	
	pthread_exit(NULL);

	return NULL;
}
