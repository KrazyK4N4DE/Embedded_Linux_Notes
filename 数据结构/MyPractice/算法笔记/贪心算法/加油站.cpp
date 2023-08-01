/*
* 加油站
*/
#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
		// 通过gas和cost对应元素相减，得到每一站的油量获得量
		// curSum记录不为负的连续和，负数的话表示从前面开始过来都是没法走到终点的，这个时候让下一站作为起点，用start记录
		// totalSum记录所有站的油量获得量
		int curSum = 0, totalSum = 0, start = 0;
		for (int i = 0; i < gas.size(); i++)
		{
				curSum += (gas[i] - cost[i]);
				totalSum += (gas[i] - cost[i]);
				if (curSum < 0)
				{
						curSum = 0;
						start = i + 1;
				}
		}
		if (totalSum < 0) return -1;
		return start;
}

int main()
{
		return 0;
}