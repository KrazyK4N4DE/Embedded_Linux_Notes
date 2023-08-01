/*ѹ���ļ�������ÿ3���ַ��еĵ�1���ַ�����������һ���ļ�
��Ҫ��������ִ��*/
#include<stdio.h>
#include<stdlib.h>		//Ϊexit()�ṩԭ��
#include<string.h>		//Ϊstrcpy()��strcat()�ṩԭ��
#define SIZE 40
int main(int argc, char* argv[])
{
	FILE* in, * out;
	int ch;
	char name[SIZE];
	int count = 0;
	//��������в���
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//��������
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open file \"%s\"\n", argv[1]);
		exit(-1);
	}
	//����Ҫ���Ƶ��ļ���
	strncpy(name, argv[1], SIZE - 5);		//SIZE-5Ϊ.red�Ϳ��ַ����ռ�
	name[SIZE - 5] = '\0';		//Ԥ������argv[1]��SIZE�������������˿��ַ�����������һ��
	strcat(name, ".red");			//��.red�ӵ�name�ַ������棬name�Ŀ��ַ���.����
	//�������
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't create file \"%s\"\n", name);
		exit(-1);
	}
	//��������
	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
		{
			putc(ch, out);
		}
	}
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files\n");
	}
	return 0;
}