/*指向结构的指针*/
#include<stdio.h>
#define MAX 20

/*第一个结构*/
struct Name
{
	char first[MAX];
	char last[MAX];
};

/*第二个结构*/
struct Info
{
	struct Name guy;
	char favfood[MAX];
	char job[MAX];
	float income;
};

/*主程序*/
int main(void)
{
	/*结构变量定义*/
	struct Info fellows[2] =
	{
		{
			{"祎","韦"},
			"牛排",
			"研究生",
			500
		},
		{
			{"梅梅","韩"},
			"大餐",
			"老总",
			30000
		}
	};
	struct Info* sb;		//指向Info结构的指针，sb不是结构名
	sb = &fellows[0];		//fellows结构名不是结构的地址，所以要加&
	printf("address #1 is: %p\taddress #2 is: %p\n", &fellows[0], &fellows[1]);
	printf("pointer #1 is: %p\tpointer #2 is: %p\n\n", sb, (sb + 1));
	printf("sb->income is: %.2f\n(*sb).income is: %.2f\n\n", sb->income, (*sb).income);		//两种写法
	sb++;
	printf("sb->favfood is: %s\n(&sb).job is: %s\nsb->guy.first is: %s\n", sb->favfood, (*sb).job, sb->guy.first);
	return 0;
}