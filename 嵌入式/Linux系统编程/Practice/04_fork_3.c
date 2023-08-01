#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int count = 0;

int main(void)
{
	pid_t pid;
	pid = fork();
	int i;

	/*Use RETURN_VALUE to judge which the process is*/
	if(pid > 0)  // parent process
	{
		for(i = 0; i < 10; i++)
		{
			printf("Hello World, count = %d\n", count++);
			sleep(1);
		}
	}
	else if(pid == 0)  // child process
	{
		while(1)
		{
			printf("I'm your son, count = %d\n", count++);
			sleep(1);
		}
	}
	else
		perror("fork");  // 弹出错误

	return 0;
}
