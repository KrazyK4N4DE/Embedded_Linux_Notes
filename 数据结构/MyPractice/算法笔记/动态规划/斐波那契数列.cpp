/**
* 使用动态规划解决斐波那契数列问题
*/
#include <iostream>
using namespace std;

inline int Fibonacci(int n)
{
		if (n < 2) return 1;
		int* dp = new int[n + 1];  // n的阶乘需要n + 1个位置，因为包括0的阶乘
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i)
				dp[i] = dp[i - 1] + dp[i - 2];  // 递推公式
		int total = dp[n];
		delete[] dp;
		return total;
}
/*精简版*/
inline int FibonacciBetter(int n)
{
		int sum = 1;
		if (n < 2) return sum;
		int dp[2] = {1, 1};
		for (int i = 2; i <= n; ++i)
		{
				sum = dp[0] + dp[1];
				dp[0] = dp[1];
				dp[1] = sum;
		}
		return sum;
}

int  main()
{
		int n;
		cout << "输入第几的数列：";
		cin >> n;
		
		cout << "结果为：" << Fibonacci(n) << endl;
		cout << "结果为：" << FibonacciBetter(n) << endl;

		return 0;
}