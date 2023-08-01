/**
* 不同路径
* 难点：dp数组含义，递推公式推导，dp数组初始化
*/
#include <iostream>
#include <vector>
using namespace std;

/*m行n列*/
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
		cout << "输入行、列：";
		cin >> m >> n;
		cout << UniquePaths(m, n) << endl;
		return 0;
}