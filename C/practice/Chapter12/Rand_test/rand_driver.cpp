/*测试rand1()和srand1()的程序，和rand_and_srand.c一起编译*/
#include<stdio.h>
extern void srand1(unsigned int seed);
extern int rand1();
int main() 
{
	unsigned int seed;
	printf("输入种子的数值：");
	while(scanf("%u",&seed)==1)
	{
		srand1(seed);
		for (int i = 0;i < 5;i++) 
		{
			printf("%d\n", rand1());
		}
		printf("输入下一个种子数值(按q滚蛋)：");
	}
	printf("Done.\n");
	return 0;
}