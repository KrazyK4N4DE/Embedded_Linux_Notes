/*
* ��������
*/
#include <iostream>
#include <vector>
using namespace std;
// ̰��
int maxSubArray(vector<int>& nums)
{
		int tmpsum = 0;  // ������¼������
		int result = INT_MIN;  // ���������������е����ֵ
		for (int i = 0; i < nums.size(); i++)
		{
				tmpsum += nums[i];
				if (tmpsum > result) result = tmpsum;
				if (tmpsum < 0) tmpsum = 0;
		}
		return result;
}
// ����
int maxSubArray_dp(vector<int>& nums)
{
		vector<int> dp(nums.size(), 0);  // dp����������¼������
		dp[0] = nums[0];
		int result = nums[0];  // ���������������е����ֵ
		for (int i = 1; i < nums.size(); i++)
		{
				dp[i] = max(nums[i], dp[i - 1] + nums[i]);
				result = max(result, dp[i]);
		}
		return result;
}

int main()
{
		return 0;
}