/**
* 不同路径2
* 难点：递推公式推导，dp数组初始化
*/
#include <iostream>
#include <vector>
using namespace std;

/*m行n列*/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
		vector<vector<int>> dp(m, vector<int>(n));
		// 初始化阶段，若第一排或第一列上有障碍物，其右/下都不用初始化为1了，因为也走不到了
		for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i)
				dp[i][0] = 1;
		for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)
				dp[0][j] = 1;
		for (int i = 1; i < m; ++i)
				for (int j = 1; j < n; ++j)
						if(obstacleGrid[i][j] == 0)
								dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		return dp[m - 1][n - 1];
}

int main()
{
		vector<vector<int>> obstacleGrid{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
		for (int i = 0; i < 3; ++i)
		{
				for (int j = 0; j < 3; ++j)
						cout << obstacleGrid[i][j] << "  ";
				cout << endl;
		}
		cout << "到终点有 " << uniquePathsWithObstacles(obstacleGrid) << " 条路径" << endl;
		return 0;
}