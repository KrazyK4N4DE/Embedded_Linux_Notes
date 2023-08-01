/*把结构数组传递给函数*/
#include<stdio.h>
#define LEN 30
#define N 2
struct banks {
	char bank[LEN];
	double bankfund;
	char save[LEN];
	double savefund;
};
double sum(const struct banks money[], int n);

int main() {
	struct banks wei[N] = {
		{"中国银行",3487.29,"中国储贷",155.64},
		{"邮政储蓄银行",77.51,"邮政储贷",944.56}
	};
	printf("Have a total of $%.2f\n", sum(wei, N));
}

/*把N个数组的银行里的钱全累加起来*/
double sum(const struct banks money[], int n) {
	double total=0;
	for (int i = 0;i < n;i++) {
		total += money[i].bankfund + money[i].savefund;
	}
	return total;
}