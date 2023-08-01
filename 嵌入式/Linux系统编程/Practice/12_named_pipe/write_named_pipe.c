/*
 * 有名管道：负责写
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Usage:\n");
		printf("%s <Message>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int fd;
	char buf[100];
	/*操作命名管道和操作文件差不多*/
	fd = open("my_fifo", O_WRONLY);
	if(fd == -1) perror("open");
	
	strcpy(buf, argv[1]);
	write(fd, buf, sizeof(buf));
	printf("Write to the pipe: %s\n", buf);

	return 0;
}
