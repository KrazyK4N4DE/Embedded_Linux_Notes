#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MY_KEY 9527

int main(void)
{
	int shm_id;
	shm_id = shmget(MY_KEY, 1024, IPC_CREAT | 0666);  // 设置创建的共享内存的权限为读写

	char* c_addr;
	c_addr = shmat(shm_id, NULL, 0);
	// 从共享内存中读数据
	printf("Read from shared memory: %s\n", c_addr);
	// 解除映射
	shmdt(c_addr);

	return 0;
}
