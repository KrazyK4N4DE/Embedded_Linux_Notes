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
	if(pid == 0)  // 子进程写管道
	{
		char ch = '*';
		int n = 0;
		while(1)
		{
			close(fd[0]);
			write(fd[1], &ch, 1);
			printf("count = %d\n", ++n);
		}
	}
	else if(pid > 0)  // 父进程等待子进程写完管道
	{
		waitpid(pid, NULL, 0);
	}
	return 0;
}
