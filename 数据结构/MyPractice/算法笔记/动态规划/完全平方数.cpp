/*
* 完全平方数：换皮零钱兑换Ⅰ
*/
#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n)
{
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i * i <= n; i++)
				for (int j = i * i; j <= n; j++)
						if (dp[j - i * i] != INT_MAX) dp[j] = min(dp[j], dp[j - i * i] + 1);
		return dp[n];
}

int main()
{
		return 0;
}