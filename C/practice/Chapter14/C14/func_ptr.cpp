/*使用函数指针*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>		//内置处理字符的函数
#define LEN 81
#pragma warning(disable:4996)		//微软认为strcpy()不安全，所以加这行头文件忽略“错误”

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
	void (*pfun)(char*);		//声明一个函数指针，被指向的函数接受char* 类型的参数，无返回值
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

/*该函数用于去掉fgets()保留的换行符*/
char* s_gets(char* str, int n)	
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
			eatline();		//清理缓冲区
		}
	}
	return returnval;
}

/*清理缓冲区*/
void eatline() {
	while (getchar() != '\n') {
		continue;
	}
}

/*展示选择菜单，读取用户的输入，并检测是否与选项字母匹配*/
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
	eatline();		//清理输入行
	while (strchr("ulton", ans) == NULL) {
		puts("Please enter the correct letter (u, l, t, o, n) : ");
		ans = tolower(getchar());		//再次输入
		eatline();		//再次清理输入行
	}
	return ans;
}

/*字符串全部转换为大写*/
void ToUpper(char* str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

/*字符串全部转换为小写*/
void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

/*字符串大小写转置*/
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

/*变为原来的字符串*/
void Dummy(char* str) {
	//nothing here
}

/*将最终选择的效果展示出来，使用到函数指针*/
void show(void(*fp)(char*), char* str) {
	(*fp)(str);		//把用户选定的函数作用于str
	puts(str);		//展示结果
}