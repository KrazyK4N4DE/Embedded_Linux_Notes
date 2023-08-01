/*
* 零钱兑换Ⅰ：完全背包问题，装满背包的最少物品数
* 难点：遍历顺序
*/
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++)
				for (int j = coins[i]; j <= amount; j++)
						if (dp[j - coins[i]] != INT_MAX)  // 如果dp[j - coins[i]]是初始值则跳过
								dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		if (dp[amount] == INT_MAX) return -1;  // 没找到任何组合
		return dp[amount];
}

int main()
{
		return 0;
}