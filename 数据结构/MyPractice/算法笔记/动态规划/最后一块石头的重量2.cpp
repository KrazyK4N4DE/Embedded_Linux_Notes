/**
* ���һ��ʯͷ�������򣺾���װ��������01�������⣬��ʯͷ�ѷֳ����ѣ��������������ȷ֣�������������õ��ľ������һ��ʯͷ��С����
* �����±�Ϊ��Ʒ������ӦԪ����ֵΪ�����ͼ�ֵ�������������Ϊ����Ԫ�غͳ���2
* �ѵ㣺����˳��
*/
#include <iostream>
#include<vector>
using namespace std;

int lastStoneWeightII(vector<int>& stones)
{
		int sum = 0;
		for (int i = 0; i < stones.size(); ++i)
				sum += stones[i];
		int target = sum / 2;

		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++)
				for (int j = target; j >= stones[i]; j--)
						dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		return sum - 2 * dp[target];
}

int main()
{
		return 0;
}