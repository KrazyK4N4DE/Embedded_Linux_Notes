/*��������ָ��ṹ��ָ��*/
#include<stdio.h>
#define FUNDLEN 50
struct funds {
	char bank[FUNDLEN];
	double bankfund;
}info;

void plus(struct funds*);

int main() {
	info = {
		"����ĸ�����",
		1209.55
	};
	printf("*****%s*****\n�������Ϊ%.2f\n\n", info.bank, info.bankfund);
	plus(&info);		//�ǵü�&
	printf("WOW���ֹǸ������˻����˵㾪ϲ�������������Ϊ%.2f", info.bankfund);
	return 0;
}

/*�ú�����Ƶ�Ŀ�ľ��Ǹı�ṹinfo�ڳ�Ա��ֵ��
�����Ʋ�����Ϊ�˸ı�ָ��ָ��ֵ�����ݣ�����structǰ�Ӹ�const*/
void plus(struct funds* money) {
	(*money).bankfund += 1000000;
}