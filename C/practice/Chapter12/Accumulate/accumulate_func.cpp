/*accumulate�ĺ�����*/
#include<stdio.h>
extern int count;		//����accumulate.c���ⲿ����count
static int total = 0;
void accumulate(int i)
{
	static int subtotal = 0;		//��̬��������ֻ��accumulate()��ʹ��
	if (i <= 0)
	{
		printf("�� %d ��ѭ��\n", count);
		printf("subtotal = %d, total = %d\n", subtotal, total);
		subtotal = 0;		//����subtotal��Ҫ��Ȼ���totalһ��
	}
	else
	{
		subtotal += i;
		total += i;
	}
}