/*
* 移除元素
*/
#include <iostream>
#include <vector>
using namespace std;

// 双指针法
int removeElement(vector<int>& nums, int val)
{
        // 快指针遍历数组，找到要删除的元素
        // 慢指针用于更新新数组的大小
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++)
        {
                // 当前元素不是要删除的话，就更新slow
                // 是的话，就跳过，到了下一个非删除元素时slow没有跟上，nums[slow] = nums[fast]就会覆盖掉要删除的元素
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