#include<stdio.h>
#define LENGTH 14
int main() {
	char words[LENGTH];
	puts("Enter a string please.");
	fgets(words, LENGTH, stdin);                                        //输入的字符串长度要求小于LENGTH，如"Apple pie"
	printf("Your string twice  (puts(), then fputs()):\n");
	puts(words);                                                                //Apple pie\n\0被保存进数组
	fputs(words, stdout);                                                               
	puts("Enter another string please.");                            //再来一遍，这次输入的字符串长度要超过LENGTH，如"Strawberry shortcake"
	fgets(words, LENGTH, stdin);
	printf("Your string twice  (puts(), then fputs()):\n");
	puts(words);                                                               //Strawberry sh\0被保存进数组
	fputs(words, stdout);
	puts("Done.");
	return 0;
}