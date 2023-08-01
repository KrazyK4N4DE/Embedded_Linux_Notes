#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

char msg[] = "Hello World";

int main(void)
{
	int shm_id;
	pid_t pid;
	shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);  // 设置创建的共享内存的权限为读写

	pid = fork();
	if(pid > 0)  // parent process
	{
		// 将共享内存映射到进程
		char* p_addr;
		p_addr = shmat(shm_id, NULL, 0);
		// 往共享内存中写东西
		memset(p_addr, '\0', sizeof(msg));
		memcpy(p_addr, msg, sizeof(msg));
		// 解除映射
		shmdt(p_addr);
		// 等待子进程结束
		waitpid(pid, NULL, 0);
	}
	else if(pid == 0)  // child process
	{
		// 映射到进程
		char* c_addr;
		c_addr = shmat(shm_id, NULL, 0);

		printf("Child process waits a short time: \n");
		sleep(2);
		printf("Child process reads from shared memory: %s\n", c_addr);
		// 解除映射
		shmdt(c_addr);
		// 删除共享内存
		shmctl(shm_id, IPC_RMID, NULL);
		printf("Shared memory destroyed\n");
	}
	else perror("fork");

	return 0;
}
