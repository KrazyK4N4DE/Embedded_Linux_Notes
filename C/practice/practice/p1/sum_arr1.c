#include<stdio.h>
#define SIZE 10
int sum(int* ar, int n);
int main() {
	int marbles[SIZE] = { 31,40,2,88,65,12,74,9,20,58 };
	int total;
	total = sum(marbles, SIZE);
	printf("sum is %d.\n", total);
	printf("The size of marbles is % zd bytes.\n", sizeof(marbles));
}
int sum(int *ar, int n) {
	int i = 0, total = 0;
	for (i;i < n;i++) {
		total += ar[i];
	}
	printf("The size of ar is %zd bytes.\n", sizeof(ar));
	return total;
}