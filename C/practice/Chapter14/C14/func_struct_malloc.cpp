/*����func_struct_pointer.cpp��ʹ��malloc()Ϊ�ṹ���ַ��������ڴ�*/
#include<stdio.h>
#include<string.h>		//�ṩstrcpy()��strlen()��ԭ��
#include<stdlib.h>		//�ṩmalloc()��free()��ԭ��
#define LEN 20
#pragma warning(disable:4996)		//΢����Ϊstrcpy()����ȫ�����Լ�����ͷ�ļ����ԡ�����
struct name {
	char* first;
	char* last;
	int letters;
}person;

char* s_gets(char*, int);
void getinfo(struct name*);
void makeinfo(struct name*);
void showinfo(const struct name*);
void cleanup(struct name*);

int main() {
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);
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

/*ͨ�������ȡ������Ϣ*/
void getinfo(struct name* pt) {
	char tmp[LEN];
	printf("Please enter ur first name.\n");
	s_gets(tmp, LEN);
	pt->first = (char*)malloc(strlen(tmp) + 1);		//�����ڴ棬+1��Ϊ�˿��ַ�
	strcpy(pt->first, tmp);		//����������˻�Ҫ��tmp�����ݸ��ƹ�ȥ
	printf("Please enter ur last name.\n");
	s_gets(tmp, LEN);
	pt->last = (char*)malloc(strlen(tmp) + 1);
	strcpy(pt->last, tmp);
}

/*�����ֵ���ĸ�����㸳ֵ���ṹ����һ��Ա*/
void makeinfo(struct name* pt) {
	(*pt).letters = strlen(pt->first) + strlen(pt->last);
}

/*����Ϣ���*/
void showinfo(const struct name* pt) {		//�ú�����Ʋ��������ı�ṹ���ݵģ����Լ�const
	printf("%s %s, ur name contains %d letters.\n", pt->first, pt->last, pt->letters);
}

/*ʹ������free()�ͷ��ڴ�*/
void cleanup(struct name* pt) {
	free(pt->first);
	free((*pt).last);
}