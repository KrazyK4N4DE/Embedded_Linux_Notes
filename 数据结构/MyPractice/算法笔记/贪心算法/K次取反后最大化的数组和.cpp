/*
* K次取反后最大化的数组和
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare_abs(int a, int b)
{
		return abs(a) > abs(b);
}
int largestSumAfterKNegations(vector<int>& nums, int k)
{
		// 按绝对值大小进行降序排序
		sort(nums.begin(), nums.end(), compare_abs);
		// 第一次贪心：优先对绝对值更大的负数进行取反，直到k用完或者负数没了
		for (int i = 0; i < nums.size(); i++)
		{
				if (nums[i] < 0 && k > 0)
				{
						nums[i] *= -1;
						k--;
				}
		}
		// 第二次贪心：若k是奇数，则将绝对值最小的非负整数取反
		if (k % 2 == 1) nums[nums.size() - 1] *= -1;
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
				res += nums[i];
		return res;
}

int main()
{
		return 0;
}