#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <fcntl.h>

int main(void)
{
	sem_t* sem_id;
	int  i = 0;
	// 创建、打开信号量
	sem_id = sem_open("NAMED_SEM", O_CREAT, 666, 0);
	// 等待信号量并进行相关处理
	while(1)
	{
		sem_wait(sem_id);
		printf("Process 1: i = %d\n", i++);
	}
	// 关闭信号量
	sem_close(sem_id);

	return 0;
}
