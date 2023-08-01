/*
使用_Alignof和_Alignas
对齐值为double(8)的变量，其地址的值以8或0结尾(能够被8整除)
*/
#include<stdio.h>
#include<cstdalign>		//为_Alignof和_Alignas提供别名
int main() {
	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	char alignas(double) cz;
	printf("char alignment: %zd\n", alignof(char));
	printf("double alignment: %zd\n", alignof(double));
	printf("&dx: %p\n", &dx);
	printf("&ca: %p\n", &ca);
	printf("&cx: %p\n", &cx);
	printf("&dz: %p\n", &dz);
	printf("&cb: %p\n", &cb);
	printf("&cz: %p\n", &cz);
	return 0;
}