#include<stdio.h>
#define MSG "I am forking special."
void main() {
	char ar[] = MSG;
	const char* ptr = MSG;
	printf("Address of \"I am forking special.\" is %p\n", "I am forking special.");
	printf("Address of MSG is %p\n", MSG);
	printf("Address of ar is %p\n", ar);
	printf("Address of ptr is %p\n", ptr);
	printf("Address of \"I am forking special.\" is %p\n", "I am forking special.");
}