/*枚举类型的值を使う*/
#include<stdio.h>
int main() {
	enum week { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
	enum week days;
	for (days = Monday;days <= Sunday;days++) {		//C++不允许出现枚举变量++
		printf("%d\n", days);
	}
	return 0;
}