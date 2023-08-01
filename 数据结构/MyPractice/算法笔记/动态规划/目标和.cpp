/**
* 目标和：纯01背包问题(装满这个背包的最大价值)。
* 难点：递推公式，初始化
*/
#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target)
{
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
				sum += nums[i];
		if (abs(target) > sum) return 0;
		if ((sum + target) % 2 != 0) return 0;
		int left = (sum + target) / 2;  // 左子集的和

		vector<int> dp(left + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < nums.size(); i++)
				for (int j = left; j >= nums[i]; j--)
						dp[j] += dp[j - nums[i]];
		return dp[left];
}

int main()
{
		return 0;
}