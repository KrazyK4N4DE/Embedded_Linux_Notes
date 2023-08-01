/*结构数组的应用*/
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

/*主程序*/
int main(void)
{
	unsigned int count = 0;
	printf("请输入书名 (想滚的话只输入回车就行) ：");

	/*开始输入循环*/
	while (s_gets(library[count].title, MAXTITLE) && count < MAXBOOKS && library[count].title[0] != '\0')
	{
		printf("再输入作者：");
		s_gets(library[count].author, MAXNAME);
		printf("多少钱呢？：");
		scanf_s("%f", &library[count++].prize);
		while (getchar() != '\n')
		{
			continue;		//清理输入行，防止缓冲区还有换行符
		}
		if (count < MAXBOOKS)
		{
			printf("请输入下一本书名 (想滚的话只输入回车就行) ：");
		}
	}

	/*开始列出输入的信息*/
	if (count > 0)
	{
		printf("以下是你的书库信息：\n");
		for (register unsigned int i = 0;i < count;i++)
		{
			printf("%s by %s: RMB%.2f\n", library[i].title, library[i].author, library[i].prize);
		}
	}
	else
	{
		printf("一本书没有？真可怜啊你");
	}
	return 0;
}

/*s_gets()的定义*/
char* s_gets(char* str, int n)
{
	char* ret_val, * find;		//声明最终返回的、查找换行符的char型指针
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