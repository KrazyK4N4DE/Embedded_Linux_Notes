/**
* ��ͬ�Ķ���������
* Ҳ�����ÿ���������ʽ���
* �ѵ㣺���ƹ�ʽ
*/
#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n)
{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= i; ++j)
						dp[i] += dp[j - 1] * dp[i - j];
		return dp[n];
}

int main()
{
		int n;
		cout << "������������";
		cin >> n;
		cout << "���Ϊ��" << numTrees(n) << endl;
		return 0;
}