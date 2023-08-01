/*
* 跳跃游戏Ⅱ
*/
#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums)
{
		if (nums.size() <= 1) return 0;
		int nextCover = 0, curCover = 0;  // 覆盖范围
		int count = 0;
		for (int index = 0; index < nums.size(); index++)
		{
				nextCover = max(index + nums[index], nextCover);  // 保证每次遍历都更新最大值
				if (index == curCover)
				{
						if (curCover < nums.size() - 1)
						{
								count++;
								curCover = nextCover;  // curCover在这里更新
						}
						else break;
				}
		}
		return count;
}

int main()
{

}