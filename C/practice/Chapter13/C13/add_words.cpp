/*���ļ�����ӵ���*/
#include<stdio.h>
#include<stdlib.h>		//Ϊexit()�ṩԭ��
#define MAX 41
int main() 
{
	FILE* fp;
	char words[MAX];
	if ((fp = fopen("FileToWrite", "a+")) == NULL) 
	{
		fprintf(stdout, "Can't open \"FileToWrite\" file.\n");
		exit(EXIT_FAILURE);
	}
	puts("���ļ���ӵ��ʡ����еĿ�ͷ����#�Ա�ʾ��ֹ���...");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%s\n", words);
	}
	puts("�ļ����ݣ�");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
	{
		puts(words);
	}
	puts("Done!");
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "�ر��ļ�����\n");
	}
	return 0;
}