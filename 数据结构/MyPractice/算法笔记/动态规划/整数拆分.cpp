/**
* 整数拆分(涉及数学，难)
* 难点：递推公式，遍历顺序
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
		cout << "输入正整数：";
		cin >> n;
		cout << "结果为：" << integerBreak(n) << endl;
		return 0;
}