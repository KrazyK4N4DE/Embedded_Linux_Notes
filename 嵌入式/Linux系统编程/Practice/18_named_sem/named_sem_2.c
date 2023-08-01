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
	// 修改umask
//	mode_t mask = umask(0);
	// 创建、打开信号量
	sem_id = sem_open("NAMED_SEM", O_CREAT, 0666, 0);
	// 还原umask
//	umask(mask);
	// 等待信号量并进行相关处理
	while(1)
	{
		printf("Process 2: i = %d\n", i++);
		sleep(2);
		sem_post(sem_id);
	}
	// 关闭信号量
	sem_close(sem_id);

	return 0;
}
