/*
* ��Ծ��Ϸ��
*/
#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums)
{
		if (nums.size() <= 1) return 0;
		int nextCover = 0, curCover = 0;  // ���Ƿ�Χ
		int count = 0;
		for (int index = 0; index < nums.size(); index++)
		{
				nextCover = max(index + nums[index], nextCover);  // ��֤ÿ�α������������ֵ
				if (index == curCover)
				{
						if (curCover < nums.size() - 1)
						{
								count++;
								curCover = nextCover;  // curCover���������
						}
						else break;
				}
		}
		return count;
}

int main()
{

}