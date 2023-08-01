/*向函数传递结构成员*/
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
		"天地银行",
		1334.27,
		"Guangxi Bank",
		595.86
	};
	printf("里面合起来金额为：%.2f", plus(info.bankfund, info.savefund));
	return 0;
}

double plus(double x, double y) {
	return (x + y);
}