/**
* ��ͬ·��
* �ѵ㣺dp���麬�壬���ƹ�ʽ�Ƶ���dp�����ʼ��
*/
#include <iostream>
#include <vector>
using namespace std;

/*m��n��*/
int UniquePaths(int m, int n)
{
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; ++i)
				dp[i][0] = 1;
		for (int j = 0; j < n; ++j)
				dp[0][j] = 1;
		for (int i = 1; i < m; ++i)
				for (int j = 1; j < n; ++j)
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		return dp[m - 1][n - 1];
}

int main()
{
		int m, n;
		cout << "�����С��У�";
		cin >> m >> n;
		cout << UniquePaths(m, n) << endl;
		return 0;
}