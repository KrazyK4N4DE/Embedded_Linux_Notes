#include<stdio.h>
#include<string.h>
#define SIZE 40
int main() {
	char s1[SIZE];
	char s2[SIZE];
	char c;
	puts("Enter 2 strings to compare:");
	while (1) {
		printf("First string: ");
		gets_s(s1, SIZE);
		printf("\nSecond string: ");
		gets_s(s2, SIZE);
		printf("\nThe return_value of comparing is: %d\n", strcmp(s1, s2));
	}
	return 0;
}