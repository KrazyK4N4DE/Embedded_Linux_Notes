/*accumulate的函数库*/
#include<stdio.h>
extern int count;		//引用accumulate.c的外部变量count
static int total = 0;
void accumulate(int i)
{
	static int subtotal = 0;		//静态变量，且只能accumulate()中使用
	if (i <= 0)
	{
		printf("第 %d 轮循环\n", count);
		printf("subtotal = %d, total = %d\n", subtotal, total);
		subtotal = 0;		//重置subtotal，要不然会跟total一样
	}
	else
	{
		subtotal += i;
		total += i;
	}
}