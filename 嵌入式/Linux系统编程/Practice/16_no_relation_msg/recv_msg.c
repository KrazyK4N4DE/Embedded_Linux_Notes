#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MY_TYPE 9527
#define MY_KEY 1314

int main(void)
{
	int msgid;

	// 定义消息队列
	struct msgbuf
	{
		long mtype;
		char mtext[100];
		int number;
	};
	struct msgbuf buff;
	// 创建消息队列
	msgid = msgget(MY_KEY, IPC_CREAT | 0666);

	while(1)
	{
		printf("Process is waiting for msg...\n");
		// 接收
		msgrcv(msgid, &buff, sizeof(buff) - sizeof(buff.mtype), MY_TYPE, 0);  // buff在传入子进程时没有被赋值
		printf("Process receive from msg: %s, %d\n", buff.mtext, buff.number);
	}
	// 销毁消息队列
	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
