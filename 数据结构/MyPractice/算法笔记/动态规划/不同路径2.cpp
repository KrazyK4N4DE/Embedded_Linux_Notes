/**
* ��ͬ·��2
* �ѵ㣺���ƹ�ʽ�Ƶ���dp�����ʼ��
*/
#include <iostream>
#include <vector>
using namespace std;

/*m��n��*/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
		vector<vector<int>> dp(m, vector<int>(n));
		// ��ʼ���׶Σ�����һ�Ż��һ�������ϰ������/�¶����ó�ʼ��Ϊ1�ˣ���ΪҲ�߲�����
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
		cout << "���յ��� " << uniquePathsWithObstacles(obstacleGrid) << " ��·��" << endl;
		return 0;
}