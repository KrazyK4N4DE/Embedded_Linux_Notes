/*
* ���������ƽ��
*/
#include <iostream>
#include <vector>
using namespace std;

// ʹ������˫ָ�뷨���ǵݼ�˳�򣬵�����������ƽ��һ����������ƽ��С������Ҫʹ������ָ��Ƚ��������˵���ƽ����С���پ����Ѵ��Ǹ��ŵ�����
vector<int> sortedSquares(vector<int>& nums)
{
        vector<int> result(nums.size());  // ���������
        int k = nums.size() - 1;
        // i <= jΪ��Ҫ�еȺţ�û�еĻ���i = jʱ���±��Ԫ��û�ܴ����ᱻ����
        // i++��j--���������ģ����Բ�д��ѭ��ͷ��
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
                if (pow(nums[i], 2) > pow(nums[j], 2))
                {
                        result[k--] = pow(nums[i], 2);
                        i++;
                }
                else
                {
                        result[k--] = pow(nums[j], 2);
                        j--;
                }
        }
        return result;
}

int main()
{
		return 0;
}