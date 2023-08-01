/*计算从1到N的累加(N由用户输入确定)，最后给出单轮累加总和(subtotal)和多轮累加总和(total)，以及总轮数，和accumulate.c一起编译*/
#include<stdio.h>
void accumulate(int i);
void report_count(void);
int count = 0;
int main()
{
	int value;
	register int k;
	printf("请输入一个正整数(0 to quit)：");
/*搞了半天最终出问题的不是多文件编译，竟是这里...说是scanf这函数不安全，会内存泄漏。
忽视这个错误的办法就是在[项目]→[属性]→[C/C++]→[预处理器]→[预处理器定义]里添加指令：_CRT_SECURE_NO_WARNINGS*/
	while (scanf("%d", &value) == 1 && value > 0)
	{
		++count;
		for (k = value;k >= 0;k--)
		{
			accumulate(k);
		}
		printf("请输入一个正整数(0 to quit)：");
	}
	report_count();
	return 0;
}

void report_count(void)
{
	printf("总共进行了%d轮累加", count);
}