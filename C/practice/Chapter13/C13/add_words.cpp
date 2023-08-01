/*在文件中添加单词*/
#include<stdio.h>
#include<stdlib.h>		//为exit()提供原型
#define MAX 41
int main() 
{
	FILE* fp;
	char words[MAX];
	if ((fp = fopen("FileToWrite", "a+")) == NULL) 
	{
		fprintf(stdout, "Can't open \"FileToWrite\" file.\n");
		exit(EXIT_FAILURE);
	}
	puts("给文件添加单词。在行的开头输入#以表示终止添加...");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%s\n", words);
	}
	puts("文件内容：");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
	{
		puts(words);
	}
	puts("Done!");
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "关闭文件错误\n");
	}
	return 0;
}