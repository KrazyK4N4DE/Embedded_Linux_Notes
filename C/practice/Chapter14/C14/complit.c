/*�����������ڽṹ��ʹ��
����C++�ı�׼�����Ժ�׺Ҫ��Ϊ.c*/
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
		readfirst = (struct books){ "����","������",20 };
	}
	else {
		readfirst = (struct books){ "��ҹ˼","���",20 };
	}
	printf("Ur assigned reading:\n��%s�� by %s, $%.2f", readfirst.title, readfirst.author, readfirst.prize);
	return 0;
}