/*���ýṹ�彨��ͼ����Ϣ*/
#include<stdio.h>
#include<string.h>
char* s_gets(char* str, int n);
#define MAXTITLE 41
#define MAXNAME 31
struct Book		//�����ṹ��
{
	char title[MAXTITLE];
	char name[MAXNAME];
	float prize;
};

int main(void)
{
	struct Book library;
	printf("����ͼ����⣺");
	s_gets(library.title, MAXTITLE);
	printf("����ͼ�����ߣ�");
	s_gets(library.name, MAXNAME);
	printf("����ͼ��۸�");
	scanf_s("%f", &library.prize);		//�ֱ��������Σ���Ӧ�ṹ��Book�������
	printf("%s by %s: RMB%.2f.\n", library.title, library.name, library.prize);
	printf("%s: \"%s\"(RMB%.2f).\n", library.name, library.title, library.prize);			//���ֱ�ʾ����
	return 0;
}

char* s_gets(char* str, int n)		//�ú�������ȥ��fgets()�����Ļ��з�
{
	char* returnval, * find;		//�������շ��صġ����һ��з���char��ָ��
	returnval = fgets(str, n, stdin);		//�ɹ�������str��ͬ�ĵ�ַ
	if (returnval)
	{
		find = strchr(str, '\n');			/*���һ��з������������ַ���λ��(��ַָ��)��ʧ���򷴻�NULL
		���������ַ�������ֻ����һ�ε����ԣ��Լ�ָ��ʽ���ַ�����ַ������ָ�룬���һ��������str��returnval������*/
		if (find)
		{
			*find = '\0';		//�ѻ��з����ɿ��ַ�
		}
		else
		{
			while (getchar() != '\n')		//��������
			{
				continue;
			}
		}
	}
	return returnval;
}