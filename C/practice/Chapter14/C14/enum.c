/*ö�����͵�ֵ��ʹ��*/
#include<stdio.h>
int main() {
	enum week { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	enum week days;
	for (days = Monday;days <= Sunday;days++) {		//C++���������ö�ٱ���++
		printf("%d\n", days);
	}
	return 0;
}