#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t pid1, pid2;
	pid1 = fork();
	pid2 = fork();
	printf("pid1 = %d, pid2 = %d\n", pid1, pid2);
	return 0;
}
