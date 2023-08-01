/*
* ��������Ľ���
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// ��set���
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
		unordered_set<int> result;
		unordered_set<int> nums_set(nums1.begin(), nums1.end());  // �Ƚ�����1�����ϣ����
		for (int num : nums2)  // �ٱ�������2
				if (nums_set.find(num) != nums_set.end())
						result.insert(num);  // ����ҵ�����ͬ��Ԫ�أ���Ԫ�ط���result��
		return vector<int>(result.begin(), result.end());  // ת����vector
}

// ��������
vector<int> intersection_arr(vector<int>& nums1, vector<int>& nums2)
{
		unordered_set<int> result;
		int hash[1005] = { 0 };  // �Ƚ�����1�����ϣ����
		for (int num : nums1) hash[num] = 1;
		for (int num : nums2)
				if (hash[num] == 1) result.insert(num);
		return vector<int>(result.begin(), result.end());  // ת����vector
}

int main()
{
		return 0;
}