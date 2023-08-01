/*
* 三数之和
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 使用双指针法之左右指针，同时三个数都要注意去重
// a + b + c = 0，用for循环中每次的当前元素表示a，当前元素的下一个表示b，数组最后一个元素表示c
vector<vector<int>> threeSum(vector<int>& nums)
{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)  // 每次遍历的当前元素就是a
		{
				if (nums[i] > 0) return result;  // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组
				if (i > 0 && nums[i] == nums[i - 1]) continue;  // a的去重
				int left = i + 1;  // b
				int right = nums.size() - 1;  // c
				while (left < right)  // left不能等于right，因为相等时，两个指针指向同一个数，就没有三数的说法了
				{
						if (nums[i] + nums[left] + nums[right] > 0) right--;
						else if (nums[i] + nums[left] + nums[right] < 0) left++;
						else
						{
								result.push_back({ nums[i], nums[left], nums[right] });
								while (left < right && nums[right] == nums[right - 1]) right--;  // b的去重
								while (left < right && nums[left] == nums[left + 1]) left++;  // c的去重
								right--;
								left++;  // 还要再减/加一次才能够到位
						}
				}
		}
		return result;
}

int main()
{
		return 0;
}