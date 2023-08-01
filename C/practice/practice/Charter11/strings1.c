#include<stdio.h>
#define MSG "I'm a common string constant."
#define MAX 81
void main() {
	char words[MAX] = "哇噢，是string in an array.";
	const char* ptr = "WOW, someone is pointing at me.";
	puts("看这里，蠢驴：");
	puts(MSG);
	puts(words);
	puts(ptr);
	words[9] = 'p';//把string中的t换成p，这里中文占两字节，故[ ]内不是5而是9
	puts(words);
}