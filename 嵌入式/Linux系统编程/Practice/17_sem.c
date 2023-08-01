#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>

int main(void)
{
	sem_t* sem_id = NULL;
	pid_t pid;
	// 使用mmap创建共享、匿名映射
	sem_id = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	// 初始化信号量
	sem_init(sem_id, 1, 1);

	pid = fork();
	if(pid > 0)
	{
		while(1)
		{
			sem_wait(sem_id);  // 等待信号量大于0
			printf("This's parent process.\n");
			sleep(1);
		}
	}
	else if(pid == 0)
	{
		while(1)
		{
			printf("This's child process.\n");
			sleep(3);
			sem_post(sem_id);  // 增加信号量
		}
	}
	else perror("fork");
		
	return 0;
}
