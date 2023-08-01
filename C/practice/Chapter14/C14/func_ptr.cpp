/*ʹ�ú���ָ��*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>		//���ô����ַ��ĺ���
#define LEN 81
#pragma warning(disable:4996)		//΢����Ϊstrcpy()����ȫ�����Լ�����ͷ�ļ����ԡ�����

char* s_gets(char* str, int n);
void eatline();
char showmenu();
void ToUpper(char*);
void ToLower(char*);
void Transpose(char*);
void Dummy(char*);
void show(void(*fp)(char*), char*);

int main() {
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char*);		//����һ������ָ�룬��ָ��ĺ�������char* ���͵Ĳ������޷���ֵ
	pfun = Dummy;
	puts("Enter a string (empty line to quit) : ");
	while (s_gets(line, LEN) != NULL && line[0] != '\0') {
		while ((choice = showmenu()) != 'n') {
			switch (choice) {
			case 'u':
				pfun = ToUpper;
				break;
			case 'l':
				pfun = ToLower;
				break;
			case 't':
				pfun = Transpose;
				break;
			case 'o':
				pfun = Dummy;
				break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("Enter a string (empty line to quit) : ");
	}
	puts("Bye!");
	return 0;
}

/*�ú�������ȥ��fgets()�����Ļ��з�*/
char* s_gets(char* str, int n)	
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
			eatline();		//��������
		}
	}
	return returnval;
}

/*��������*/
void eatline() {
	while (getchar() != '\n') {
		continue;
	}
}

/*չʾѡ��˵�����ȡ�û������룬������Ƿ���ѡ����ĸƥ��*/
char showmenu() {
	char ans;
	puts("\nEnter menu choice: ");
	puts("-----------------------------------------------");
	puts("  u ) upper case                   l ) lower case");
	puts("  t  ) transposed case          o ) original case");
	puts("  n ) next string");
	puts("-----------------------------------------------\n");
	ans = getchar();
	ans = tolower(ans);
	eatline();		//����������
	while (strchr("ulton", ans) == NULL) {
		puts("Please enter the correct letter (u, l, t, o, n) : ");
		ans = tolower(getchar());		//�ٴ�����
		eatline();		//�ٴ�����������
	}
	return ans;
}

/*�ַ���ȫ��ת��Ϊ��д*/
void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

/*�ַ���ȫ��ת��ΪСд*/
void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

/*�ַ�����Сдת��*/
void Transpose(char* str) {
	while (*str) {
		if (islower(*str)) {
			*str = toupper(*str);
		}
		else if (isupper(*str)) {
			*str = tolower(*str);
		}
		str++;
	}
}

/*��Ϊԭ�����ַ���*/
void Dummy(char* str) {
	//nothing here
}

/*������ѡ���Ч��չʾ������ʹ�õ�����ָ��*/
void show(void(*fp)(char*), char* str) {
	(*fp)(str);		//���û�ѡ���ĺ���������str
	puts(str);		//չʾ���
}