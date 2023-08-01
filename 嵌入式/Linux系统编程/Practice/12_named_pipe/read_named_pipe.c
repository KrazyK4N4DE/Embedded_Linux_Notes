/*
 * 有名管道：负责读
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd;
	char buf[100];
	int ret;
	ret = mkfifo("my_fifo", 666);  // 在当前文件夹下创建FIFO文件，名为my_fifo，没有操作权限，为666
	if(ret) perror("mkfifo");

	printf("Prepare reading from named pipe...\n");
	/*操作命名管道和操作文件差不多*/
	fd = open("my_fifo", O_RDWR);
	if(fd == -1) perror("open");
	// 读该文件，会进入阻塞状态，直到有其他进程写该文件
	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		read(fd, buf, sizeof(buf));
		printf("Read from named pipe: %s\n", buf);
		sleep(1);
	}

	return 0;
}
