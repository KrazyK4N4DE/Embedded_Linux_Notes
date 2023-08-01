#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Run model: ./a.out 10 5 15 (three child process, after 10, 5, 15seconds, they're over)*/
int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		printf("Usage:\n");
		printf("%s <DelayTime> <DelayTime> <DelayTime>\n", argv[0]);
		return -1;
	}

	pid_t child_pid;
	int deadNum = 0;

	for(int i = 1; i < argc; i++)
	{
		switch(fork())
		{
			case -1:
				perror("fork()");
				exit(0);
			case 0:  //  是子进程的话就输出信息并定时
				printf("Child %d started with PID %d, sleeping in %s seconds.\n", i, getpid(), argv[i]);
				sleep(atoi(argv[i]));
				exit(0);
			default:  // 是父进程的话就跳出去等待
				break;
		}
	}

	while(1)
	{
		child_pid = wait(NULL);
		if(child_pid == -1)  // 都没有子进程了
		{
			printf("No Children process, bye!\n");
			exit(0);
		}

		printf("wait() returned child PID: %d (deadNum = %d).\n", child_pid, ++deadNum);
	}

	return 0;
}
