/*��̬��������*/
#include<stdio.h>
#include<stdlib.h>		//Ϊmalloc()��free()�ṩԭ��
int main() 
{
	double * ptd;
	int max, number;
	int i = 0;
	puts("�����������Ԫ�ظ�����");
	if (scanf("%d", &max) != 1) 
	{
		puts("�������ݲ��ԣ�����");
		exit(EXIT_FAILURE);
	}
	ptd = (double*)malloc(max * sizeof(double));		//malloc()�����ڴ�
	if (ptd == NULL)
	{
		printf("�ڴ����ʧ�ܣ�����");
		exit(EXIT_FAILURE);
	}
	puts("�����Ԫ��ֵ(��q����)��");
	while(i<max&&scanf("%lf",&ptd[i])==1)		//��ȡ���������ֵ��֪��������max
	{
		++i;
	}
	printf("�ܹ�%d�������£�\n", number = i);
	for (i = 0;i < number;i++) 
	{
		printf("%7.2lf  ", ptd[i]);
		if (i % 7 == 6)		//ÿ����ͷ����7��Ԫ�ؾͻ���
		{
			putchar('\n');
		}
	}
	if (i % 7 != 0)		//�պ���7��7�ı�����Ԫ��ʱ�������Ѿ��������ˣ�����Ͳ�����
	{
		putchar('\n');
	}
	puts("Done.");
	free(ptd);		//�ͷ��ڴ�
	return 0;
}