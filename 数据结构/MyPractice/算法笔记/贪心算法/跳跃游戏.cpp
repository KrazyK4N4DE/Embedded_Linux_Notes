/*
* ��Ծ��Ϸ
*/
#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums)
{
		if (nums.size() <= 1) return true;
		int cover = 0;  // ���Ƿ�Χ
		for (int index = 0; index <= cover; index++)  // ����̬���¸��Ƿ�Χ���ж��Ƿ񸲸����յ�λ��
		{
				cover = max(index + nums[index], cover);  // ��֤ÿ�α������������ֵ
				if (cover >= nums.size() - 1) return true;
		}
		return false;
}

int main()
{
		return 0;
}