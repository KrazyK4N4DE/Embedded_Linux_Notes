/*
* 四数之和
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 仍旧使用双指针法之左右指针，就是在三数之和外再套一个循环，同时四个数都要注意剪枝和去重
// a + b + c + d = target，两层for循环的当前遍历元素是a和b，固定的，剪枝和去重操作变复杂了
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size(); k++)
		{
				if (nums[k] > target && nums[k] > 0 && target > 0) return result;  // 一级剪枝
				if (k > 0 && nums[k] == nums[k - 1]) continue;  // 一级去重
				for (int i = k + 1; i < nums.size(); i++)
				{
						if (nums[k] + nums[i] > target && nums[k] + nums[i] > 0 && target > 0) return result;  // 二级剪枝
						if (i > k + 1 && nums[i] == nums[i - 1]) continue;  // 二级去重
						int left = i + 1;  // b
						int right = nums.size() - 1;  // c
						while (left < right)
						{
								if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
								else if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
								else
								{
										result.push_back({ nums[k], nums[i], nums[left], nums[right] });
										while (left < right && nums[right] == nums[right - 1]) right--;
										while (left < right && nums[left] == nums[left + 1]) left++;
										right--;
										left++;  // 还要再减/加一次才能够到位
								}
						}
				}
		}
		return result;
}

int main()
{
		return 0;
}