#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if(pid > 0)
	{
		sleep(10);
		kill(pid, SIGKILL);
	}
	else if(pid == 0)
	{
		int i = 0;
		while(1)
		{
			printf("Count to %d\n", ++i);
			sleep(1);
		}
	}
	else perror("fork");

	return 0;
}
