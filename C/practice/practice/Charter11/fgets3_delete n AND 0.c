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
			words[i] = '\0';                          //�ѻ��з����ɿ��ַ������ָ�����ġ�'\n'֮����ַ������������ǲ��̶��Ĵ��룬���ԼǼ�
		}
		else                                              //words[i]=='\0'��ʱ��
		{
			while (getchar() != '\n') {          //����'\n'֮����ַ��Ͳ��ٶ�����������
				continue;
			}
		}
		puts(words);
	}
	puts("Done.");
	return 0;
}