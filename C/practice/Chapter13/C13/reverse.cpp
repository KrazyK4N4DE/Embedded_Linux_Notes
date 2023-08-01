/*倒序显示文件的内容*/
#include<stdio.h>
#include<stdlib.h>
#define CTNL_Z '\032'		//DOS文本文件中的文件结尾标记
#define LEN 81
int main()
{
	char filename[LEN];
	char ch;
	FILE* fp;
	long count, last;
	printf("请输入要tenet的文件名：");
	scanf("%80s", filename);
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open file \"%s\"\n", filename);
		exit(-1);
	}
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	for (count = 1L;count <= last;count++)
	{
		fseek(fp, -count, SEEK_END);
		ch = getc(fp);
		if (ch != CTNL_Z && ch != '\r')
		{
			putchar(ch);
		}
	}
	fclose(fp);
	return 0;
}