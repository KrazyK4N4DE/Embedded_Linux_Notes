/*传递指向结构的指针的函数，有双向传递*/
#include<stdio.h>
#include<string.h>
#define LEN 20
struct name {
	char first[LEN];
	char last[LEN];
	int letters;
}person;

char* s_gets(char*, int);
void getinfo(struct name*);
void makeinfo(struct name*);
void showinfo(const struct name*);

int main() {
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
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

/*通过输入获取名字信息*/
void getinfo(struct name* pt) {
	printf("Please enter ur first name.\n");
	s_gets(pt->first, LEN);
	printf("Please enter ur last name.\n");
	s_gets(pt->last, LEN);
}

/*将名字的字母数计算赋值给结构的另一成员*/
void makeinfo(struct name* pt) {
	(*pt).letters = strlen(pt->first) + strlen(pt->last);
}

/*将信息输出*/
void showinfo(const struct name* pt) {		//该函数设计不是用来改变结构内容的，所以加const
	printf("%s %s, ur name contains %d letters.\n", pt->first, pt->last, pt->letters);
}