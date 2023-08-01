#include<stdio.h>
int main() {
	int ref[] = { 8,4,0,2 };
	int* ptr;
	int i;
	for (i = 0, ptr = ref;i < 4;i++, ptr++) {
		printf("%d  %d\n", ref[i], *ptr);
	}
	return 0;
}