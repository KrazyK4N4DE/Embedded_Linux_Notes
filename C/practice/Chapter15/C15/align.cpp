/*
ʹ��_Alignof��_Alignas
����ֵΪdouble(8)�ı��������ַ��ֵ��8��0��β(�ܹ���8����)
*/
#include<stdio.h>
#include<cstdalign>		//Ϊ_Alignof��_Alignas�ṩ����
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