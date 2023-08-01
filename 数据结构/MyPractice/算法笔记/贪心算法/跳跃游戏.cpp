/*
* 跳跃游戏
*/
#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums)
{
		if (nums.size() <= 1) return true;
		int cover = 0;  // 覆盖范围
		for (int index = 0; index <= cover; index++)  // 靠动态更新覆盖范围，判断是否覆盖了终点位置
		{
				cover = max(index + nums[index], cover);  // 保证每次遍历都更新最大值
				if (cover >= nums.size() - 1) return true;
		}
		return false;
}

int main()
{
		return 0;
}