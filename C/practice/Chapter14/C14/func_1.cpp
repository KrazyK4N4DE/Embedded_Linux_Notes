/*�������ݽṹ��Ա*/
#include<stdio.h>
#define FUNDLEN 50
struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
}info;

double plus(double, double);

int main() {
	info = {
		"�������",
		1334.27,
		"Guangxi Bank",
		595.86
	};
	printf("������������Ϊ��%.2f", plus(info.bankfund, info.savefund));
	return 0;
}

double plus(double x, double y) {
	return (x + y);
}