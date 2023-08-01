#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int fd[2];

	if(pipe(fd) == -1) perror("pipe");

	pid = fork();
	if(pid == 0)  // 子进程输入写管道
	{
		char tmp[100];
		close(fd[0]);

		while(1)
		{
			scanf("%s", tmp);
			write(fd[1], tmp, sizeof(tmp));
		}
	}
	else if(pid > 0)  // 父进程读管道输入
	{
		char tmp[100];
		close(fd[1]);
		printf("Parent process is waiting for the data from pipe...\n");
		while(1)
		{
			read(fd[0], tmp, sizeof(tmp));
			printf("Read from pipe: %s\n", tmp);
		}
	}
	return 0;
}
