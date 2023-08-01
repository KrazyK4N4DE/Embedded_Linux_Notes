/*
* 最大公约数GCD与最小公倍数LCM
*/
#include <iostream>
using namespace std;

// 最大公约数：欧几里得算法
int gcd(int a, int b)
{
		return b ? gcd(b, a % b) : a;
}

// 最小公倍数：两数乘积 除以 其最大公约数
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