/*ָ��ṹ��ָ��*/
#include<stdio.h>
#define MAX 20

/*��һ���ṹ*/
struct Name
{
	char first[MAX];
	char last[MAX];
};

/*�ڶ����ṹ*/
struct Info
{
	struct Name guy;
	char favfood[MAX];
	char job[MAX];
	float income;
};

/*������*/
int main(void)
{
	/*�ṹ��������*/
	struct Info fellows[2] =
	{
		{
			{"�t","Τ"},
			"ţ��",
			"�о���",
			500
		},
		{
			{"÷÷","��"},
			"���",
			"����",
			30000
		}
	};
	struct Info* sb;		//ָ��Info�ṹ��ָ�룬sb���ǽṹ��
	sb = &fellows[0];		//fellows�ṹ�����ǽṹ�ĵ�ַ������Ҫ��&
	printf("address #1 is: %p\taddress #2 is: %p\n", &fellows[0], &fellows[1]);
	printf("pointer #1 is: %p\tpointer #2 is: %p\n\n", sb, (sb + 1));
	printf("sb->income is: %.2f\n(*sb).income is: %.2f\n\n", sb->income, (*sb).income);		//����д��
	sb++;
	printf("sb->favfood is: %s\n(&sb).job is: %s\nsb->guy.first is: %s\n", sb->favfood, (*sb).job, sb->guy.first);
	return 0;
}