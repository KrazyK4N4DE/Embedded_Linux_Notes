/**
* �������(�漰��ѧ����)
* �ѵ㣺���ƹ�ʽ������˳��
*/
#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n)
{
		if (n <= 2)
		{
				if (n <= 0)
						return 0;
				return n - 1;
		}
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 0;
		dp[2] = 1;
		for (int i = 3; i <= n; ++i)
				for (int j = 1; j <= i / 2; ++j)
						dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
		return dp[n];
}

int main()
{
		int n;
		cout << "������������";
		cin >> n;
		cout << "���Ϊ��" << integerBreak(n) << endl;
		return 0;
}