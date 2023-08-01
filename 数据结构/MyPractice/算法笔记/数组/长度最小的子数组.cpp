/*
* 长度最小的子数组
*/
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
		int ans = INT_MAX;  // 用于比较
		int sum = 0;
		int start = 0, end = 0;
		for (; end < nums.size(); end++)
		{
				sum += nums[end];
				while (sum >= target)
				{
						ans = (ans <= (end - start + 1) ? ans : (end - start + 1));
						sum -= nums[start++];
				}
		}
		return ans == INT_MAX ? 0 : ans;
}

int main()
{
		return 0;
}