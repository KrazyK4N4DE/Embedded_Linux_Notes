#include<stdio.h>
int main()
{
	char ch;
	FILE* fp;
	fp = fopen("FileToWrite", "r");
	while ((ch=getc(fp)) != EOF)
	{
		putc(ch, stdout);		//�ȼ���putchar(ch);
	}
	return 0;
}