/*�ṹ�����Ӧ��*/
#include<stdio.h>
#include<string.h>
#define MAXTITLE 41
#define MAXNAME 21
#define MAXBOOKS 100
char* s_gets(char* str, int n);
struct
{
	char title[MAXTITLE];
	char author[MAXNAME];
	float prize;
}library[MAXBOOKS];

/*������*/
int main(void)
{
	unsigned int count = 0;
	printf("���������� (����Ļ�ֻ����س�����) ��");

	/*��ʼ����ѭ��*/
	while (s_gets(library[count].title, MAXTITLE) && count < MAXBOOKS && library[count].title[0] != '\0')
	{
		printf("���������ߣ�");
		s_gets(library[count].author, MAXNAME);
		printf("����Ǯ�أ���");
		scanf_s("%f", &library[count++].prize);
		while (getchar() != '\n')
		{
			continue;		//���������У���ֹ���������л��з�
		}
		if (count < MAXBOOKS)
		{
			printf("��������һ������ (����Ļ�ֻ����س�����) ��");
		}
	}

	/*��ʼ�г��������Ϣ*/
	if (count > 0)
	{
		printf("��������������Ϣ��\n");
		for (register unsigned int i = 0;i < count;i++)
		{
			printf("%s by %s: RMB%.2f\n", library[i].title, library[i].author, library[i].prize);
		}
	}
	else
	{
		printf("һ����û�У����������");
	}
	return 0;
}

/*s_gets()�Ķ���*/
char* s_gets(char* str, int n)
{
	char* ret_val, * find;		//�������շ��صġ����һ��з���char��ָ��
	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}