#include<stdio.h>
#define MAX 10
int main() {
	char words[MAX];
	int i;
	puts("Please enter some strings:");
	while (fgets(words, MAX, stdin) != NULL && words[0] != '\n') {
		i = 0;
		while (words[i] != '\n' && words[i] != '\0') {
			i++;
		}
		if (words[i] == '\n') {
			words[i] = '\0';                          //把换行符换成空字符，这种跟下面的“'\n'之后的字符都抛弃”都是差不多固定的代码，可以记记
		}
		else                                              //words[i]=='\0'的时候
		{
			while (getchar() != '\n') {          //读到'\n'之后的字符就不再读进缓冲区了
				continue;
			}
		}
		puts(words);
	}
	puts("Done.");
	return 0;
}