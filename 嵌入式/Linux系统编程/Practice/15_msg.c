#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MY_TYPE 9527

// 删除fgets的换行
void deleteLine(char* str)
{
	if(str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
}

int main(void)
{
	pid_t pid;
	int msgid;

	// 定义消息队列
	struct msgbuf
	{
		long mtype;
		char mtext[100];
		int number;
	};
	struct msgbuf buff;
	// 结构体大小应该为112bytes，为8的整数倍
	printf("sizeof(struct msgbuf) = %ld\n", sizeof(struct msgbuf));

	// 创建消息队列
	msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);

	pid = fork();
	if(pid > 0)  // parent process，发送消息队列
	{
		sleep(3);
		// 填充结构体的信息
		buff.mtype = MY_TYPE;
		printf("Please enter a string: \n");
		fgets(buff.mtext, sizeof(buff.mtext), stdin);
		deleteLine(buff.mtext);
		printf("Please enter a number: \n");
		scanf("%d", &buff.number);

		msgsnd(msgid, &buff, sizeof(buff) - sizeof(buff.mtype), 0);
		waitpid(pid, NULL, 0);
	}
	else if(pid == 0)  // child process，接收消息队列
	{
		printf("Child process is waiting for msg...\n");
		// 接收
		msgrcv(msgid, &buff, sizeof(buff) - sizeof(buff.mtype), MY_TYPE, 0);  // buff在传入子进程时没有被赋值
		printf("Child process receive from msg: %s, %d\n", buff.mtext, buff.number);
		// 销毁消息队列
		msgctl(msgid, IPC_RMID, NULL);
	}
	else perror("fork");

	return 0;
}
