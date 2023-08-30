/*
* 卡特兰数公式
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
		int total = 1;
		for (int i = 1; i <= n; ++i) total *= i;
		return total;
}

int main()
{
		int n;
		cout << "输入结点数：";
		cin >> n;

		if (n < 0)
		{
				cout << "结点数量不能为负数！\n";
				return -1;
		}

		cout << "由卡特兰序列得出，" << n << " 个结点可以构造出 " << factorial(2 * n) / (factorial(n) * factorial(n + 1)) << " 种不同的二叉树\n";
		return 0;
}