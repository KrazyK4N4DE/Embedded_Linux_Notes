/*
* 螺旋矩阵Ⅱ(LeetCode59)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums(n, vector<int>(n, 0));  // 用来作返回值
        int startx = 0, starty = 0;
        int offset = 1, count = 1;  // offset为每次转圈的偏移量，保证每圈的边界条件不变：每一行/列遍历到最后一个元素前一位
        int i, j;
        int loop = n / 2;  // 每转完一圈，行/列的边就少两条
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
        if (n % 2 == 1) nums[n / 2][n / 2] = count;  // 边数为奇数时把中间最后一个空给填上
        return nums;
}

int main()
{
		return 0;
}