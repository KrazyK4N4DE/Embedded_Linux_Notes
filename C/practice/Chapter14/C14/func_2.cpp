/*向函数传递指向结构的指针*/
#include<stdio.h>
#define FUNDLEN 50
struct funds {
	char bank[FUNDLEN];
	double bankfund;
}info;

void plus(struct funds*);

int main() {
	info = {
		"随便哪个银行",
		1209.55
	};
	printf("*****%s*****\n您的余额为%.2f\n\n", info.bank, info.bankfund);
	plus(&info);		//记得加&
	printf("WOW，钢骨给您的账户来了点惊喜！现在您的余额为%.2f", info.bankfund);
	return 0;
}

/*该函数设计的目的就是改变结构info内成员的值，
如果设计并不是为了改变指针指向值的内容，就在struct前加个const*/
void plus(struct funds* money) {
	(*money).bankfund += 1000000;
}