/*�ѽṹ���鴫�ݸ�����*/
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
		{"�й�����",3487.29,"�й�����",155.64},
		{"������������",77.51,"��������",944.56}
	};
	printf("Have a total of $%.2f\n", sum(wei, N));
}

/*��N��������������Ǯȫ�ۼ�����*/
double sum(const struct banks money[], int n) {
	double total=0;
	for (int i = 0;i < n;i++) {
		total += money[i].bankfund + money[i].savefund;
	}
	return total;
}