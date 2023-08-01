#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

char msg[] = "Hello World";

#define MY_KEY 9527  // 自定一个键值，不用IPC_PRIVATE让内核来随机分配

int main(void)
{
	int shm_id;
	shm_id = shmget(MY_KEY, 1024, IPC_CREAT | 0666);  // 设置创建的共享内存的权限为读写

	char* p_addr;
	p_addr = shmat(shm_id, NULL, 0);
	// 往共享内存中写东西
	memset(p_addr, '\0', sizeof(msg));
	memcpy(p_addr, msg, sizeof(msg));
	// 解除映射
	shmdt(p_addr);

	return 0;
}
