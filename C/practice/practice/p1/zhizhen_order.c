#include<stdio.h>
int main() {
	int dt[2] = { 100,200 }, mdt[2] = { 300,400 };
	int* p1, * p2, * p3;
	p1 = p2 = dt;
	p3 = mdt;
	printf("*p1=%d, *p2=%d, *p3=%d\n", *p1, *p2, *p3);
	printf("*p1++=%d, *++p2=%d, (*p3)++=%d\n", *p1++, *++p2, (*p3)++);
	printf("*p1=%d, *p2=%d, *p3=%d\n", *p1, *p2, *p3);
	return 0;
}