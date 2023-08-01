/*
* ���������(LeetCode59)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums(n, vector<int>(n, 0));  // ����������ֵ
        int startx = 0, starty = 0;
        int offset = 1, count = 1;  // offsetΪÿ��תȦ��ƫ��������֤ÿȦ�ı߽��������䣺ÿһ��/�б��������һ��Ԫ��ǰһλ
        int i, j;
        int loop = n / 2;  // ÿת��һȦ����/�еı߾�������
        while (loop--)
        {
                for (j = starty; j < n - offset; j++)
                        nums[startx][j] = count++;
                for (i = startx; i < n - offset; i++)
                        nums[i][j] = count++;
                for (; j > starty; j--)
                        nums[i][j] = count++;
                for (; i > startx; i--)
                        nums[i][j] = count++;
                startx++;
                starty++;
                offset++;
        }
        if (n % 2 == 1) nums[n / 2][n / 2] = count;  // ����Ϊ����ʱ���м����һ���ո�����
        return nums;
}

int main()
{
		return 0;
}