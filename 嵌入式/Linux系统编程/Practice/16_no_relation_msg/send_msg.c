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

// 删除fgets的换行
void deleteLine(char* str)
{
	if(str[strlen(str)-1] == '\n') str[strlen(str)-1] = '\0';
}

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

	// 填充结构体的信息
	buff.mtype = MY_TYPE;
	printf("Please enter a string: \n");
	fgets(buff.mtext, sizeof(buff.mtext), stdin);
	deleteLine(buff.mtext);
	printf("Please enter a number: \n");
	scanf("%d", &buff.number);
	// 发送消息队列
	msgsnd(msgid, &buff, sizeof(buff) - sizeof(buff.mtype), 0);

	return 0;
}
