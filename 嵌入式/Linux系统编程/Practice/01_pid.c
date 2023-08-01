#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;

	while(1)
	{
		printf("pid = %d\n", getpid());	
		printf("ppid = %d\n", getppid());
		printf("HelloWorld\n\n");
		sleep(1);
	}

	return 0;
}
