/*Ƕ�׽ṹ��Ӧ��*/
#include<stdio.h>
#define MAX 20
const char* msg[4] =
{
	"�ܸ�����ʶ�㣬",
	"�����Ҽ�ʶ����2022���˻�������ô������",
	"Ϊ��л���ؿ��ҵ���Ұ���Ҿ������������ϲ���Ե�",
	"��˳�������ٿ������ܲ��ܸ���"
};

/*��һ���ṹ*/
struct Name
{
	char first[MAX];
	char last[MAX];
};

/*�ڶ����ṹ*/
struct Guy
{
	struct Name handle;
	char favfood[MAX];
	char job[MAX];
	float income;
};

int main(void)
{
	struct Guy fellow =
	{
		{"�t","Τ"},
		"ţ��",
		"�о���",
		500
	};
	printf("��%s%s��\n%4s", fellow.handle.last, fellow.handle.first,"");
	printf("%s%s%s��\n", msg[0], fellow.handle.last, fellow.handle.last);
	printf("%s%s��\n", msg[1], fellow.job);
	printf("%s%s%s", msg[2], fellow.favfood, msg[3]);
	
	/*��ʼ�ݽ�*/
	if (fellow.income > 10000)
	{
		puts("��");
	}
	else if (fellow.income > 5000)
	{
		puts("��");
	}
	else
	{
		puts("����");
	}

	printf("\n%60s%s\n", "", "somebody");
	printf("%60s%s\n", "", "2022.06.17");
	return 0;
}