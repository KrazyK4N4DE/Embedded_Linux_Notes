#include<stdio.h>

typedef struct {
	char a;
	char b;
	char c;
} T1;		//sizeof(T1) = 3
typedef struct {
	short int a;
	T1 t1;
} T2;		// 6

#pragma pack(8)		//预编译命令，用于定义基本对齐系数，这里可以改成4或8，看看效果怎样
struct one {
	double d;
	char c;
	int i;
};
struct two {
	char c;
	double d;
	int i;
};
#pragma pack()		//用于取消自定义基本字节对齐系数

#pragma pack(8)
struct s1 {
	char c;
	int i;
	short s;
};		// 12
#pragma pack()
struct A {
	bool a : 1;
	unsigned int b : 3;
	unsigned int c : 1;
	unsigned int d : 9;
};

int main() {
	printf("sizeof(T1) = %d\nsizeof(T2) = %d\n", sizeof(T1), sizeof(T2));
	printf("sizeof(one) = %d\nsizeof(two) = %d\n", sizeof(one), sizeof(two));
	printf("sizeof(s1) = %d\n", sizeof(s1));
	return 0;
}