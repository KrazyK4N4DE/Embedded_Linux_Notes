/*
* �Ƴ�Ԫ��
*/
#include <iostream>
#include <vector>
using namespace std;

// ˫ָ�뷨
int removeElement(vector<int>& nums, int val)
{
        // ��ָ��������飬�ҵ�Ҫɾ����Ԫ��
        // ��ָ�����ڸ���������Ĵ�С
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++)
        {
                // ��ǰԪ�ز���Ҫɾ���Ļ����͸���slow
                // �ǵĻ�����������������һ����ɾ��Ԫ��ʱslowû�и��ϣ�nums[slow] = nums[fast]�ͻḲ�ǵ�Ҫɾ����Ԫ��
                if (nums[fast] != val)
                {
                        nums[slow] = nums[fast];
                        slow++;
                }
        }
        return slow;
}

int main()
{
		return 0;
}