/*
* 一和零：装满这个背包有多少物品
难点：遍历顺序
*/
#include <iostream>
#include<vector>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
		// 初始化了
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (string str : strs)  // 遍历物品
		{
				int x = 0, y = 0;  // 记录单个字符串0和1的个数
				for (char c : str)
				{
						if (c == '0') x++;
						else y++;
				}
				// 遍历背包，两个维度，两层循环；要倒序遍历
				for (int i = m; i >= x; i--)
						for (int j = n; j >= y; j--)
								dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
		}
		return dp[m][n];
}

int main()
{
		return 0;
}