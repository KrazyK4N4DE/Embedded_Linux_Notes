/*����rand1()��srand1()�ĳ��򣬺�rand_and_srand.cһ�����*/
#include<stdio.h>
extern void srand1(unsigned int seed);
extern int rand1();
int main() 
{
	unsigned int seed;
	printf("�������ӵ���ֵ��");
	while(scanf("%u",&seed)==1)
	{
		srand1(seed);
		for (int i = 0;i < 5;i++) 
		{
			printf("%d\n", rand1());
		}
		printf("������һ��������ֵ(��q����)��");
	}
	printf("Done.\n");
	return 0;
}