/*
ʹ��λ������ʾ������
��ȡ�û����������������������ȷ��0��1��ϣ��������ַ�����
*/
#include<stdio.h>
#include<limits.h>		//�ṩCHAR_BIT�Ķ��壬��ʾÿ�ֽڵ�λ��
char* itobs(int, char*);
void show_bstr(const char*);
int invert_end(int num, int bits);

int main() {
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	int number;
	printf("sizeof(int) is %d bytes\n", sizeof(int));
	puts("�������� (������������֣��������): ");
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

/*����ת���ɶ������ַ���*/
char* itobs(int n, char* ps) {
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for (i = size - 1;i >= 0;i--, n >>= 1) {		//ÿ��ѭ����һ��0��λ���ٰ�1��λ������0��λ
		ps[i] = (1 & n) + '0';		//'0'��ASCII��ֵΪ0��&Ϊ��λ����������Զ���ɶ����������бȽ�
	}
	ps[size] = '\0';		//�ַ������Կ��ַ���β�ģ����ӵĻ������ʱû�п��ַ�����һֱ��ӡ��֪���������ַ�λΪֹ
	return ps;
}

/*4λһ����ʾ�������ַ���*/
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