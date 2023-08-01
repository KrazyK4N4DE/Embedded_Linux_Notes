/*
* ����֮��
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ʹ��˫ָ�뷨֮����ָ�룬ͬʱ��������Ҫע��ȥ��
// a + b + c = 0����forѭ����ÿ�εĵ�ǰԪ�ر�ʾa����ǰԪ�ص���һ����ʾb���������һ��Ԫ�ر�ʾc
vector<vector<int>> threeSum(vector<int>& nums)
{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)  // ÿ�α����ĵ�ǰԪ�ؾ���a
		{
				if (nums[i] > 0) return result;  // ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ��
				if (i > 0 && nums[i] == nums[i - 1]) continue;  // a��ȥ��
				int left = i + 1;  // b
				int right = nums.size() - 1;  // c
				while (left < right)  // left���ܵ���right����Ϊ���ʱ������ָ��ָ��ͬһ��������û��������˵����
				{
						if (nums[i] + nums[left] + nums[right] > 0) right--;
						else if (nums[i] + nums[left] + nums[right] < 0) left++;
						else
						{
								result.push_back({ nums[i], nums[left], nums[right] });
								while (left < right && nums[right] == nums[right - 1]) right--;  // b��ȥ��
								while (left < right && nums[left] == nums[left + 1]) left++;  // c��ȥ��
								right--;
								left++;  // ��Ҫ�ټ�/��һ�β��ܹ���λ
						}
				}
		}
		return result;
}

int main()
{
		return 0;
}