/*�����Ӻ���������dicemain.cһ�����*/
#include"diceroll.h"
#include<stdio.h>
#include<stdlib.h>		//�ṩ�⺯��rand()��ԭ��
int roll_count = 0;
static int rolldice(int sides)		/*�����������ӵĽ���ĺ�����static��ʾ�ú������ڸ��ļ�˽��*/
{
	int roll;
	roll = rand() % sides + 1;		//������������õ��Ľ��Ϊ1~����
	++roll_count;		//����rolldice�������ô���
	return roll;
}
int dice_sides(int dice, int sides)		/*���������������������Ĳ�������ģ��n������Ͷ�������ܺ�*/
{
	int total = 0;
	if (sides < 2) 
	{
		printf("һ������������Ҫ2����(side)��\n");
		return -2;
	}
	if (dice < 1) 
	{
		printf("������Ҫ1��1����(die)��\n");
		return -1;
	}
	for (int i = 0;i < dice;i++)		//��ʼͶ���� 
	{
		total += rolldice(sides);
	}
	return total;
}
