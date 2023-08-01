/*掷骰子函数程序，与dicemain.c一起编译*/
#include"diceroll.h"
#include<stdio.h>
#include<stdlib.h>		//提供库函数rand()的原型
int roll_count = 0;
static int rolldice(int sides)		/*掷出单个骰子的结果的函数，static表示该函数属于该文件私有*/
{
	int roll;
	roll = rand() % sides + 1;		//处理随机数，得到的结果为1~面数
	++roll_count;		//计算rolldice函数调用次数
	return roll;
}
int dice_sides(int dice, int sides)		/*接受骰子数、骰子面数的参数，并模拟n个骰子投出来的总和*/
{
	int total = 0;
	if (sides < 2) 
	{
		printf("一个骰子至少需要2个面(side)！\n");
		return -2;
	}
	if (dice < 1) 
	{
		printf("至少需要1个1骰子(die)！\n");
		return -1;
	}
	for (int i = 0;i < dice;i++)		//开始投骰子 
	{
		total += rolldice(sides);
	}
	return total;
}
