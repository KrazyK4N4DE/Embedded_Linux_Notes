/*
* �ڶ�����
*/
#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
		int prediff = 0;  // ��֤������ǰƽ��
		int curdiff = 0;  // �������ʼ��
		int count = 1;  // ������1
		for (int i = 0; i < nums.size() - 1; i++)
		{
				curdiff = nums[i + 1] - nums[i];
				if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0))  // prediffҪ���� = 0���������ΪҪ������������ƽ��
				{
						count++;
						prediff = curdiff;  // д��if��
				}
		}
		return count;
}

int main()
{
		return 0;
}