/*�ֲ���̬�������ڿ���ʹ��static���η�*/
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
	static int stay = 1;		//Ϊ�ֲ���̬������������һ��֮�󲻻���ִ����
	printf("fade = %d, stay = %d\n", fade++, stay++);
}