/*
* 组合总和Ⅳ：完全背包问题，涉及排列
*/
#include <iostream>
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target)
{
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		// 先遍历背包再遍历物品
		for (int j = 0; j <= target; j++)
				for (int i = 0; i < nums.size(); i++)
						if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) dp[j] += dp[j - nums[i]];
		return dp[target];
}

int main()
{
		return 0;
}