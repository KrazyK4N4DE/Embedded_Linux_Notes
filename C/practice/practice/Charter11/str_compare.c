#include<stdio.h>
#include<string.h>
#define ANSWER "Brad"
#define MAXSIZE 40
int main() {
	int i = 0;
	char try[MAXSIZE];
	puts("Who is buried in Michael De Santa's tomb?");
	fgets(try, MAXSIZE, stdin);
	while (try[i] != '\n') {
		i++;
	}
	try[i] = '\0';
	while (strcmp(try, ANSWER) != 0) {  //可改进的地方：试试字符串处理函数将输入的字符串全部转换成小写再进行比较
		puts("Trevor you fool!!!");
		fgets(try, MAXSIZE, stdin);
		i = 0;
		while (try[i] != '\n') {
			i++;
		}
		try[i] = '\0';
	}
	puts("That's right!");
	return 0;
}