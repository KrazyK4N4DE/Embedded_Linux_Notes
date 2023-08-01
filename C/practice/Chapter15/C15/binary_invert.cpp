/*
使用位操作显示二进制
读取用户输入的整数，程序计算出正确的0和1组合，并放入字符串中
*/
#include<stdio.h>
#include<limits.h>		//提供CHAR_BIT的定义，表示每字节的位数
char* itobs(int, char*);
void show_bstr(const char*);
int invert_end(int num, int bits);

int main() {
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;
	printf("sizeof(int) is %d bytes\n", sizeof(int));
	puts("输入整数 (输入非整数数字，程序结束): ");
	while (scanf_s("%d", &number) == 1) {
		itobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Inverting the last 4 bits gives.\n");
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	puts("BYE!");
	return 0;
}

/*整数转换成二进制字符串*/
char* itobs(int n, char* ps) {
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1;i >= 0;i--, n >>= 1) {		//每次循环存一个0号位，再把1号位右移至0号位
		ps[i] = (1 & n) + '0';		//'0'的ASCII码值为0；&为按位与运算符，自动变成二进制数进行比较
	}
	ps[size] = '\0';		//字符串是以空字符结尾的，不加的话，输出时没有空字符，会一直打印，知道遇见空字符位为止
	return ps;
}

/*4位一组显示二进制字符串*/
void show_bstr(const char* str) {
	int i = 0;
	while (str[i]) {
		putchar(str[i]);
		if (++i % 4 == 0 && str[i]) {
			putchar(' ');
		}
	}
}

/**/
int invert_end(int num, int bits) {
	int mask = 0;
	int bitval = 1;
	while (bits-- > 0) {
		mask |= bitval;
		bitval <<= 1;
	}
	return num ^ mask;
}