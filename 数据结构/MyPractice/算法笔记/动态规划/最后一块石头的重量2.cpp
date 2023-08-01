/**
* 最后一块石头的重量Ⅱ：尽量装满背包的01背包问题，将石头堆分成两堆，两堆重量尽量等分，这样两堆相减得到的就是最后一块石头最小质量
* 数组下标为物品名，对应元素数值为重量和价值，背包最大容量为数组元素和除以2
* 难点：遍历顺序
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