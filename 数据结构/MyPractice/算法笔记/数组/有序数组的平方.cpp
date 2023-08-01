/*
* 有序数组的平方
*/
#include <iostream>
#include <vector>
using namespace std;

// 使用左右双指针法，非递减顺序，但不代表负数的平方一定比正数的平方小，所以要使用左右指针比较两个极端的数平方大小，再决定把大那个放到后面
vector<int> sortedSquares(vector<int>& nums)
{
        vector<int> result(nums.size());  // 存放新数组
        int k = nums.size() - 1;
        // i <= j为何要有等号？没有的话，i = j时该下标的元素没能处理，会被落下
        // i++和j--是有条件的，所以不写在循环头中
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