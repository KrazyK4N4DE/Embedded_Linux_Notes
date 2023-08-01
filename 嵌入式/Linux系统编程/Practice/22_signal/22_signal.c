#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void fun(int sig);

int main(void)
{
	int i = 0;
	printf("Current pid = %d\n", getpid());
	signal(SIGINT, fun);
	signal(SIGQUIT, fun);
	while(1)
	{
		printf("Count to %d\n", ++i);
		sleep(1);
	}

	return 0;
}

void fun(int sig)
{
	if(sig == SIGINT)
	{
		printf("\nYou have just triggered a Ctrl+C operation.\n");
		exit(1);
	}
	else if(sig == SIGQUIT)
	{
		printf("\nYou have just triggered a \"SIGQUIT\" signal.\n");
		exit(1);
	}
}
