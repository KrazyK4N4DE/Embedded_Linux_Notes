/*���ݽṹ�ĺ���*/
#include<stdio.h>
#include<string.h>
#define LEN 20
struct name {
	char first[LEN];
	char last[LEN];
	int letters;
}person;

char* s_gets(char*, int);
struct name getinfo();
struct name makeinfo(struct name);
void showinfo(const struct name);

int main() {
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);
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
struct name getinfo() {
	struct name tmp;
	printf("Please enter ur first name.\n");
	s_gets(tmp.first, LEN);
	printf("Please enter ur last name.\n");
	s_gets(tmp.last, LEN);
	return tmp;
}

/*�����ֵ���ĸ�����㸳ֵ���ṹ����һ��Ա*/
struct name makeinfo(struct name pt) {
	pt.letters = strlen(pt.first) + strlen(pt.last);
	return pt;
}

/*����Ϣ���*/
void showinfo(const struct name pt) {		//�ú�����Ʋ��������ı�ṹ���ݵģ����Լ�const
	printf("%s %s, ur name contains %d letters.\n", pt.first, pt.last, pt.letters);
}