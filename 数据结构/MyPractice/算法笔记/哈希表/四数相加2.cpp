/*
* 四数相加Ⅱ
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
		unordered_map<int, int> map;
		int count = 0;
		// 先遍历前两个数组
		for (int a : nums1)
				for (int b : nums2)
						map[a + b]++;
		// 后遍历后两个数组
		for (int c : nums3)
		{
				for (int d : nums4)
				{
						auto iter = map.find(0 - (c + d));  // a + b = 0 - (c + d)
						if (iter != map.end())
								count += iter->second;  // count加的是当前key对应的value
				}
		}
		return count;
}

int main()
{
		return 0;
}