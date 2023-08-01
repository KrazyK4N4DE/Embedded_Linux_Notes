/*
* 摆动序列
*/
#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
		int prediff = 0;  // 保证至少有前平坡
		int curdiff = 0;  // 这个随便初始化
		int count = 1;  // 至少是1
		for (int i = 0; i < nums.size() - 1; i++)
		{
				curdiff = nums[i + 1] - nums[i];
				if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0))  // prediff要考虑 = 0的情况，因为要考虑上下坡有平坡
				{
						count++;
						prediff = curdiff;  // 写在if里
				}
		}
		return count;
}

int main()
{
		return 0;
}