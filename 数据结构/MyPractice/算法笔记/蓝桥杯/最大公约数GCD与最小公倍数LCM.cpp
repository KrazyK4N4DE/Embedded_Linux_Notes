/*
* ���Լ��GCD����С������LCM
*/
#include <iostream>
using namespace std;

// ���Լ����ŷ������㷨
int gcd(int a, int b)
{
		return b ? gcd(b, a % b) : a;
}

// ��С�������������˻� ���� �����Լ��
int lcm(int a, int b)
{
		return a * b / gcd(a, b);
}

int main()
{
		int x = 15, y = 25;
		cout << "x = " << x
				<< ", y = " << y
				<< "\nGCD: " << gcd(x, y)
				<< "\nLCM: " << lcm(x, y) << endl;

		return 0;
}