/*局部静态变量：在块中使用static修饰符*/
#include<stdio.h>
void trystat(void);
int main(void) 
{
	for(int count=1;count<=3;count++)
	{
		printf("Here comes the iteration %d\n", count);
		trystat();
	}
	return 0;
}

void trystat(void) 
{
	int fade = 1;
	static int stay = 1;		//为局部静态变量，声明了一次之后不会再执行了
	printf("fade = %d, stay = %d\n", fade++, stay++);
}