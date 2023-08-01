/*改自func_struct_pointer.cpp，使用malloc()为结构的字符串分配内存*/
#include<stdio.h>
#include<string.h>		//提供strcpy()、strlen()的原型
#include<stdlib.h>		//提供malloc()、free()的原型
#define LEN 20
#pragma warning(disable:4996)		//微软认为strcpy()不安全，所以加这行头文件忽略“错误”
struct name {
	char* first;
	char* last;
	int letters;
}person;

char* s_gets(char*, int);
void getinfo(struct name*);
void makeinfo(struct name*);
void showinfo(const struct name*);
void cleanup(struct name*);

int main() {
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);
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
	char tmp[LEN];
	printf("Please enter ur first name.\n");
	s_gets(tmp, LEN);
	pt->first = (char*)malloc(strlen(tmp) + 1);		//分配内存，+1是为了空字符
	strcpy(pt->first, tmp);		//分配完别忘了还要把tmp的内容复制过去
	printf("Please enter ur last name.\n");
	s_gets(tmp, LEN);
	pt->last = (char*)malloc(strlen(tmp) + 1);
	strcpy(pt->last, tmp);
}

/*将名字的字母数计算赋值给结构的另一成员*/
void makeinfo(struct name* pt) {
	(*pt).letters = strlen(pt->first) + strlen(pt->last);
}

/*将信息输出*/
void showinfo(const struct name* pt) {		//该函数设计不是用来改变结构内容的，所以加const
	printf("%s %s, ur name contains %d letters.\n", pt->first, pt->last, pt->letters);
}

/*使用两次free()释放内存*/
void cleanup(struct name* pt) {
	free(pt->first);
	free((*pt).last);
}