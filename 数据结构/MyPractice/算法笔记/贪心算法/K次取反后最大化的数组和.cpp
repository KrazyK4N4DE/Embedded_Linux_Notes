/*
* K��ȡ������󻯵������
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
		// ������ֵ��С���н�������
		sort(nums.begin(), nums.end(), compare_abs);
		// ��һ��̰�ģ����ȶԾ���ֵ����ĸ�������ȡ����ֱ��k������߸���û��
		for (int i = 0; i < nums.size(); i++)
		{
				if (nums[i] < 0 && k > 0)
				{
						nums[i] *= -1;
						k--;
				}
		}
		// �ڶ���̰�ģ���k���������򽫾���ֵ��С�ķǸ�����ȡ��
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