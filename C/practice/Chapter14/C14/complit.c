/*复合字面量在结构的使用
不是C++的标准，所以后缀要改为.c*/
#include<stdio.h>
#define MAX 41
struct books {
	char title[MAX];
	char author[MAX];
	float prize;
};

int main() {
	struct books readfirst;
	unsigned int score;
	printf("Please enter ur score: ");
	scanf_s("%u", &score);
	if (score >= 84) {
		readfirst = (struct books){ "无题","李商隐",20 };
	}
	else {
		readfirst = (struct books){ "静夜思","李白",20 };
	}
	printf("Ur assigned reading:\n《%s》 by %s, $%.2f", readfirst.title, readfirst.author, readfirst.prize);
	return 0;
}