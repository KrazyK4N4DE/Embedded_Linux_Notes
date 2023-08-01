/**
* 爬楼梯，从1阶开始推导发现是斐波那契数列，用动态规划
* 难点：推出递推公式
*/
#include <iostream>
using namespace std;

int Stair(int n)
{
		if (n < 3) return n;
		int sum = 0;
		int dp[3] = { 0, 1, 2};
		for (int i = 3; i <= n; ++i)
		{
				sum = dp[1] + dp[2];
				dp[1] = dp[2];
				dp[2] = sum;
		}
		return sum;
}

int main()
{
		int n;
		cout << "输入阶数：";
		cin >> n;
		cout << "结果为：" << Stair(n) << endl;

		return 0;
}