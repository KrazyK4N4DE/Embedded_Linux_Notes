/*向函数传递结构成员*/
#include<stdio.h>
#define FUNDLEN 50
struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
}info;

double plus(struct funds);

int main() {
	info = {
		"天地银行",
		1334.27,
		"Guangxi Bank",
		595.86
	};
	printf("里面合起来金额为：%.2f", plus(info));		//传递的是结构
	return 0;
}

double plus(struct funds tmp) {
	return (tmp.bankfund + tmp.savefund);
}