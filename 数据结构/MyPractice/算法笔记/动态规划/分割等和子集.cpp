/**
* �ָ�Ⱥ��Ӽ������Գ���Ϊ01�������⣬���������ܷ�װ������
* �����±�Ϊ��Ʒ������ӦԪ��ֵΪ�����ͼ�ֵ�������������Ϊ����Ԫ�غͳ���2
* �ѵ㣺���ƹ�ʽ������˳��
*/
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums)
{
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
				sum += nums[i];
		if (sum % 2 != 0) return false;  // �����Ͳ���
		int target = sum / 2;

		vector<int> dp(target + 1, 0);
		for (int i = 0; i < nums.size(); i++)
				for (int j = target; j >= nums[i]; j--)
						dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		return dp[target] == target;
}

int main()
{
		return 0;
}
