/*
* ����֮��
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �Ծ�ʹ��˫ָ�뷨֮����ָ�룬����������֮��������һ��ѭ����ͬʱ�ĸ�����Ҫע���֦��ȥ��
// a + b + c + d = target������forѭ���ĵ�ǰ����Ԫ����a��b���̶��ģ���֦��ȥ�ز����临����
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size(); k++)
		{
				if (nums[k] > target && nums[k] > 0 && target > 0) return result;  // һ����֦
				if (k > 0 && nums[k] == nums[k - 1]) continue;  // һ��ȥ��
				for (int i = k + 1; i < nums.size(); i++)
				{
						if (nums[k] + nums[i] > target && nums[k] + nums[i] > 0 && target > 0) return result;  // ������֦
						if (i > k + 1 && nums[i] == nums[i - 1]) continue;  // ����ȥ��
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
										left++;  // ��Ҫ�ټ�/��һ�β��ܹ���λ
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