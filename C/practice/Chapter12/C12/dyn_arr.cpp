/*动态分配数组*/
#include<stdio.h>
#include<stdlib.h>		//为malloc()、free()提供原型
int main() 
{
	double * ptd;
	int max, number;
	int i = 0;
	puts("设置最大数组元素个数：");
	if (scanf("%d", &max) != 1) 
	{
		puts("输入内容不对，滚蛋");
		exit(EXIT_FAILURE);
	}
	ptd = (double*)malloc(max * sizeof(double));		//malloc()分配内存
	if (ptd == NULL)
	{
		printf("内存分配失败，滚蛋");
		exit(EXIT_FAILURE);
	}
	puts("输入各元素值(按q滚蛋)：");
	while(i<max&&scanf("%lf",&ptd[i])==1)		//读取键盘输入的值，知道数量够max
	{
		++i;
	}
	printf("总共%d个，如下：\n", number = i);
	for (i = 0;i < number;i++) 
	{
		printf("%7.2lf  ", ptd[i]);
		if (i % 7 == 6)		//每从行头到第7个元素就换行
		{
			putchar('\n');
		}
	}
	if (i % 7 != 0)		//刚好有7或7的倍数的元素时，上面已经换过行了，这里就不用了
	{
		putchar('\n');
	}
	puts("Done.");
	free(ptd);		//释放内存
	return 0;
}