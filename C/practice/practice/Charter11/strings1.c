#include<stdio.h>
#define MSG "I'm a common string constant."
#define MAX 81
void main() {
	char words[MAX] = "���ޣ���string in an array.";
	const char* ptr = "WOW, someone is pointing at me.";
	puts("�������¿��");
	puts(MSG);
	puts(words);
	puts(ptr);
	words[9] = 'p';//��string�е�t����p����������ռ���ֽڣ���[ ]�ڲ���5����9
	puts(words);
}