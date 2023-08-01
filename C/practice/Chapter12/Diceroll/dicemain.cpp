/*模拟掷骰子的程序，用到diceroll.c的函数*/
#include"diceroll.h"		//为dice_sides()原型和roll_count变量提供声明
#include<stdio.h>
#include<stdlib.h>		//为库函数srand()提供原型
#include<time.h>		//为time()提供原型
int main()
{
	int roll, dice, sides, status;
	srand((unsigned)time(0));		//随机种子，传入空指针0给time()，返回实时变化的时间值，从而种子也是变化的，获得随机效果
	printf("输入单个骰子的面数：");
	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("要投多少个骰子：");
		if (status = scanf("%d", &dice) != 1) 
		{
			if (status == EOF)		//读取到文件结尾，程序滚蛋
			{
				break;
			}
			else		//输入类型不匹配，scanf()返回0
			{
				printf("你应该输入一个整数...\n");
				printf("再来\n");
				while (getchar() != '\n')
				/*这个有用，输错的字符会在缓冲区，需要靠这个getchar()一个个读取来消掉，读到回车键程序就重新循环了。
				如果没有这个循环处理，接下来程序就直接滚蛋了*/
				{
					continue;
				}
				printf("输入面数(按0滚蛋)：");
				continue;
			}
		}
		roll = dice_sides(dice, sides);
		printf("你投了%d个%d面的骰子，总和为%d\n", dice, sides, roll);
		printf("输入面数(按0滚蛋)：");
	}
	printf("diceroll函数总共用了%d次\n", roll_count);
	return 0;
}