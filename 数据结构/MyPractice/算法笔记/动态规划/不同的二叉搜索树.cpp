/**
* 不同的二叉搜索树
* 也可以用卡特兰数公式解决
* 难点：递推公式
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
		cout << "输入正整数：";
		cin >> n;
		cout << "结果为：" << numTrees(n) << endl;
		return 0;
}