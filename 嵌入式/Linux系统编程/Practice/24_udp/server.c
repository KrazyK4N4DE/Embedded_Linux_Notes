#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT_ID 8800
#define SIZE 100

int main(void)
{
	int server_fd;
	struct sockaddr_in server_addr, client_addr;
	int addr_len = sizeof(struct sockaddr);
	char buf[SIZE];
		
	// 1. socket()
	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	// 2. bind()
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_ID);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bind(server_fd, (const struct sockaddr*)&server_addr, addr_len);

	while(1)
	{
		printf("Server is waiting for client to connect...\n");
		// 3. recvfrom()
		recvfrom(server_fd, buf, SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);  // 将源放入参数列表
		printf("Server received from client: %s\n", buf);
	}
	// 4. close()
	close(server_fd);

	return 0;
}
