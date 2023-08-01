/**
* 分割等和子集：可以抽象为01背包问题，给定重量能否装满背包
* 数组下标为物品名，对应元素值为重量和价值，背包最大容量为数组元素和除以2
* 难点：递推公式，遍历顺序
*/
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums)
{
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
				sum += nums[i];
		if (sum % 2 != 0) return false;  // 奇数就不用
		int target = sum / 2;

		vector<int> dp(target + 1, 0);
		for (int i = 0; i < nums.size(); i++)
				for (int j = target; j >= nums[i]; j--)
						dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		return dp[target] == target;
}

int main()
{
		return 0;
}
