/*�����1��N���ۼ�(N���û�����ȷ��)�������������ۼ��ܺ�(subtotal)�Ͷ����ۼ��ܺ�(total)���Լ�����������accumulate.cһ�����*/
#include<stdio.h>
void accumulate(int i);
void report_count(void);
int count = 0;
int main()
{
	int value;
	register int k;
	printf("������һ��������(0 to quit)��");
/*���˰������ճ�����Ĳ��Ƕ��ļ����룬��������...˵��scanf�⺯������ȫ�����ڴ�й©��
�����������İ취������[��Ŀ]��[����]��[C/C++]��[Ԥ������]��[Ԥ����������]�����ָ�_CRT_SECURE_NO_WARNINGS*/
	while (scanf("%d", &value) == 1 && value > 0)
	{
		++count;
		for (k = value;k >= 0;k--)
		{
			accumulate(k);
		}
		printf("������һ��������(0 to quit)��");
	}
	report_count();
	return 0;
}

void report_count(void)
{
	printf("�ܹ�������%d���ۼ�", count);
}