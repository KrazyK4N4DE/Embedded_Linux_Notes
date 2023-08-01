/*
* 零钱兑换Ⅱ：完全背包问题，涉及组合
*/
#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins)
{
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < coins.size(); i++)
				for (int j = coins[i]; j <= amount; j++)
						dp[j] += dp[j - coins[i]];
		return dp[amount];
}

int main()
{
		return 0;
}