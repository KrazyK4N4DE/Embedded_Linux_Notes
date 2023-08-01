/*利用结构体建立图书信息*/
#include<stdio.h>
#include<string.h>
char* s_gets(char* str, int n);
#define MAXTITLE 41
#define MAXNAME 31
struct Book		//声明结构体
{
	char title[MAXTITLE];
	char name[MAXNAME];
	float prize;
};

int main(void)
{
	struct Book library;
	printf("输入图书标题：");
	s_gets(library.title, MAXTITLE);
	printf("输入图书作者：");
	s_gets(library.name, MAXNAME);
	printf("输入图书价格：");
	scanf_s("%f", &library.prize);		//分别输入三次，对应结构体Book里的类型
	printf("%s by %s: RMB%.2f.\n", library.title, library.name, library.prize);
	printf("%s: \"%s\"(RMB%.2f).\n", library.name, library.title, library.prize);			//两种表示方法
	return 0;
}

char* s_gets(char* str, int n)		//该函数用于去掉fgets()保留的换行符
{
	char* returnval, * find;		//声明最终返回的、查找换行符的char型指针
	returnval = fgets(str, n, stdin);		//成功返回与str相同的地址
	if (returnval)
	{
		find = strchr(str, '\n');			/*查找换行符，函数返回字符的位置(地址指针)，失败则反回NULL
		这里由于字符串常量只储存一次的特性，以及指针式把字符串地址拷贝给指针，则第一个参数填str或returnval都可以*/
		if (find)
		{
			*find = '\0';		//把换行符换成空字符
		}
		else
		{
			while (getchar() != '\n')		//清理缓冲区
			{
				continue;
			}
		}
	}
	return returnval;
}