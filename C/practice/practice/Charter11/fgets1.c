#include<stdio.h>
#define LENGTH 14
int main() {
	char words[LENGTH];
	puts("Enter a string please.");
	fgets(words, LENGTH, stdin);                                        //������ַ�������Ҫ��С��LENGTH����"Apple pie"
	printf("Your string twice  (puts(), then fputs()):\n");
	puts(words);                                                                //Apple pie\n\0�����������
	fputs(words, stdout);                                                               
	puts("Enter another string please.");                            //����һ�飬���������ַ�������Ҫ����LENGTH����"Strawberry shortcake"
	fgets(words, LENGTH, stdin);
	printf("Your string twice  (puts(), then fputs()):\n");
	puts(words);                                                               //Strawberry sh\0�����������
	fputs(words, stdout);
	puts("Done.");
	return 0;
}