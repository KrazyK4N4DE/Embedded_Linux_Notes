/*���ļ����ж����ַ�
��Ҫ����������ִ��*/
#include<stdio.h>
#include<stdlib.h>		//Ϊexit()�ṩԭ��
int main(int argc, char* argv[])
{
	int ch;		//�����ļ�ʱ������ÿ���ַ��ĵط�
	FILE* fp;
	unsigned long count = 0;
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(-1);		//EXIT_FAILURE���Ƿ�0
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("��ô�򲻿�%s��\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);		//���з�Ҳ�㣬ֻҪ�����ļ���β
		count++;
	}
	fclose(fp);
	printf("�ļ�%s��һ��%lu���ַ�\n", argv[1], count);		//ע��lu����ul
	return 0;
}