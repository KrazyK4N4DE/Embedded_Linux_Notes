/**
* 使用最小花费爬楼梯
* 难点：递推公式推导，dp数组初始化
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
		int sum = 0;
		int n = cost.size();
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 0;
		int i = 2;
		for (; i <= n; ++i)
		{
				dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
				sum = dp[i];
		}
		return sum;
}

int main()
{
		return 0;
}