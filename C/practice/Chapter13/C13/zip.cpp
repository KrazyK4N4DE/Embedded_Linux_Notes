/*压缩文件：保留每3个字符中的第1个字符，并存入另一个文件
需要在命令行执行*/
#include<stdio.h>
#include<stdlib.h>		//为exit()提供原型
#include<string.h>		//为strcpy()、strcat()提供原型
#define SIZE 40
int main(int argc, char* argv[])
{
	FILE* in, * out;
	int ch;
	char name[SIZE];
	int count = 0;
	//检查命令行参数
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//设置输入
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
		exit(-1);
	}
	//设置要复制的文件名
	strncpy(name, argv[1], SIZE - 5);		//SIZE-5为.red和空字符留空间
	name[SIZE - 5] = '\0';		//预防，若argv[1]比SIZE还长，拷贝不了空字符，就主动加一个
	strcat(name, ".red");			//将.red加到name字符串后面，name的空字符被.覆盖
	//设置输出
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't create file \"%s\"\n", name);
		exit(-1);
	}
	//拷贝数据
	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
		{
			putc(ch, out);
		}
	}
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files\n");
	}
	return 0;
}