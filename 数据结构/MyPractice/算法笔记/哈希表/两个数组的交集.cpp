/*
* 两个数组的交集
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 用set解决
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
		unordered_set<int> result;
		unordered_set<int> nums_set(nums1.begin(), nums1.end());  // 先将数组1放入哈希表中
		for (int num : nums2)  // 再遍历数组2
				if (nums_set.find(num) != nums_set.end())
						result.insert(num);  // 如果找到了相同的元素，把元素放入result中
		return vector<int>(result.begin(), result.end());  // 转换成vector
}

// 用数组解决
vector<int> intersection_arr(vector<int>& nums1, vector<int>& nums2)
{
		unordered_set<int> result;
		int hash[1005] = { 0 };  // 先将数组1放入哈希表中
		for (int num : nums1) hash[num] = 1;
		for (int num : nums2)
				if (hash[num] == 1) result.insert(num);
		return vector<int>(result.begin(), result.end());  // 转换成vector
}

int main()
{
		return 0;
}