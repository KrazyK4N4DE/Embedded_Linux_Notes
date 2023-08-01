/*
* 递增子序列
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
private:
        vector<vector<int>> results;
        vector<int> path;
        void backtracking(vector<int>& nums, int startIndex)  // 没法用used来去重，因为数组不能进行排序
        {
                if (path.size() > 1) results.push_back(path);  // 题目说了，数组里至少两个数
                unordered_set<int> uset;
                for (int i = startIndex; i < nums.size(); i++)
                {
                        if (!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) continue;
                        uset.insert(nums[i]);  // uset不用回溯，因为每递归一次，都会新建一个局部uset，只需记录本层是否有重复的数
                        path.push_back(nums[i]);
                        backtracking(nums, i + 1);
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> findSubsequences(vector<int>& nums) 
        {
                backtracking(nums, 0);
                return results;
        }
};

int main()
{
        return 0;
}