/*ģ�������ӵĳ����õ�diceroll.c�ĺ���*/
#include"diceroll.h"		//Ϊdice_sides()ԭ�ͺ�roll_count�����ṩ����
#include<stdio.h>
#include<stdlib.h>		//Ϊ�⺯��srand()�ṩԭ��
#include<time.h>		//Ϊtime()�ṩԭ��
int main()
{
	int roll, dice, sides, status;
	srand((unsigned)time(0));		//������ӣ������ָ��0��time()������ʵʱ�仯��ʱ��ֵ���Ӷ�����Ҳ�Ǳ仯�ģ�������Ч��
	printf("���뵥�����ӵ�������");
	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("ҪͶ���ٸ����ӣ�");
		if (status = scanf("%d", &dice) != 1) 
		{
			if (status == EOF)		//��ȡ���ļ���β���������
			{
				break;
			}
			else		//�������Ͳ�ƥ�䣬scanf()����0
			{
				printf("��Ӧ������һ������...\n");
				printf("����\n");
				while (getchar() != '\n')
				/*������ã������ַ����ڻ���������Ҫ�����getchar()һ������ȡ�������������س������������ѭ���ˡ�
				���û�����ѭ�����������������ֱ�ӹ�����*/
				{
					continue;
				}
				printf("��������(��0����)��");
				continue;
			}
		}
		roll = dice_sides(dice, sides);
		printf("��Ͷ��%d��%d������ӣ��ܺ�Ϊ%d\n", dice, sides, roll);
		printf("��������(��0����)��");
	}
	printf("diceroll�����ܹ�����%d��\n", roll_count);
	return 0;
}