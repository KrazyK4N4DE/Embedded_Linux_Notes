/*�������ݽṹ��Ա*/
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
		"�������",
		1334.27,
		"Guangxi Bank",
		595.86
	};
	printf("������������Ϊ��%.2f", plus(info));		//���ݵ��ǽṹ
	return 0;
}

double plus(struct funds tmp) {
	return (tmp.bankfund + tmp.savefund);
}