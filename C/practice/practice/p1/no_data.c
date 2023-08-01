#include<stdio.h>
#define SIZE 7
int main() {
	int arr[SIZE];
	printf("%-2s%18s\n", "i", "no_data[]");
	for (int i = 0;i < SIZE;i++) {
		printf("%-2d%18d\n", i, arr[i]);
	}
	return 0;
}