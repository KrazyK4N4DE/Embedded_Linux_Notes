/*
* 最大子序和
*/
#include <iostream>
#include <vector>
using namespace std;
// 贪心
int maxSubArray(vector<int>& nums)
{
		int tmpsum = 0;  // 用来记录连续和
		int result = INT_MIN;  // 用来更新连续和中的最大值
		for (int i = 0; i < nums.size(); i++)
		{
				tmpsum += nums[i];
				if (tmpsum > result) result = tmpsum;
				if (tmpsum < 0) tmpsum = 0;
		}
		return result;
}
// 动规
int maxSubArray_dp(vector<int>& nums)
{
		vector<int> dp(nums.size(), 0);  // dp数组用来记录连续和
		dp[0] = nums[0];
		int result = nums[0];  // 用来更新连续和中的最大值
		for (int i = 1; i < nums.size(); i++)
		{
				dp[i] = max(nums[i], dp[i - 1] + nums[i]);
				result = max(result, dp[i]);
		}
		return result;
}

int main()
{
		return 0;
}