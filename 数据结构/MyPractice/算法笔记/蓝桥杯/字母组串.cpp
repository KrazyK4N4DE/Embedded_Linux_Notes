/*
* ��ĸ�鴮
*/
#include <iostream>
using namespace std;

//  a��A��b��B��c��C ��ĸ������ɶ��ٸ���ͬ�ĳ���Ϊn���ַ���
int f(int a, int b, int c, int n)
{
		if (a < 0 || b < 0 || c < 0) return 0;  // ��֦
		if (n == 0) return 1;  // n����ĸ�����ˣ�����ʾ����˳���Ϊn���ַ���
		return f(a - 1, b, c, n - 1) + f(a, b - 1, c, n - 1) + f(a, b, c - 1, n - 1);
}

int main()
{
		cout << f(1, 1, 1, 2) << endl;
		cout << f(1, 2, 3, 3) << endl;
		return 0;
}