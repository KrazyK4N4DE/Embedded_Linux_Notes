/*数文件里有多少字符
需要在命令行中执行*/
#include<stdio.h>
#include<stdlib.h>		//为exit()提供原型
int main(int argc, char* argv[])
{
	int ch;		//处理文件时，接收每个字符的地方
	FILE* fp;
	unsigned long count = 0;
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(-1);		//EXIT_FAILURE就是非0
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("怎么打不开%s啊\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);		//换行符也算，只要不是文件结尾
		count++;
	}
	fclose(fp);
	printf("文件%s里一共%lu个字符\n", argv[1], count);		//注意lu不是ul
	return 0;
}