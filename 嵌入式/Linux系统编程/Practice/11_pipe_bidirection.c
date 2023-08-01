/*
 * 双向管道：父进程传字符串给子进程，子进程再转换为大写再传回去
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	pid_t pid;
	/*双向需要两个管道*/
	int fd1[2];  // 用于父进程传给子进程
	int fd2[2];  // 用于子进程传给父进程

	if(pipe(fd1) == -1) perror("pipe");
	if(pipe(fd2) == -1) perror("pipe");

	pid = fork();
	if(pid == 0)  // 子进程
	{
		char tmp[100];
		close(fd1[1]);
		close(fd2[0]);

		while(1)
		{
			memset(tmp, '\0', sizeof(tmp));
			read(fd1[0], tmp, sizeof(tmp));
			/*转换大写*/
			for(int i = 0; i < sizeof(tmp); ++i)
				tmp[i] = toupper(tmp[i]);
			
			write(fd2[1], tmp, sizeof(tmp));  // 写
		}
	}
	else if(pid > 0)  // 父进程
	{
		char tmp[100];
		close(fd1[0]);
		close(fd2[1]);

		while(1)
		{
			memset(tmp, '\0', sizeof(tmp));
			fgets(tmp, sizeof(tmp), stdin);  // 键入
			write(fd1[1], tmp, sizeof(tmp));  // 写
			memset(tmp, '\0', sizeof(tmp));
			read(fd2[0], tmp, sizeof(tmp));  // 读
			printf("After change: %s\n", tmp);
		}
	}
	return 0;
}
