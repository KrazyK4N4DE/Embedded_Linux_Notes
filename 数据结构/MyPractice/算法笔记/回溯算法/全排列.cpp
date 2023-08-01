/*
* 全排列
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
        vector<vector<int>> results;
        vector<int> path;
        void backtracking(vector<int>& nums, vector<bool>& branch)
        {
                if (path.size() == nums.size())
                {
                        results.push_back(path);
                        return;
                }
                for (int i = 0; i < nums.size(); i++)  // i从0开始，不用startIndex，是因为组合中元素内容一样、顺序不一样也算同一个，所以上层的下一次遍历要排除掉之前的
                {
                        if (branch[i] == true) continue;
                        branch[i] = true;
                        path.push_back(nums[i]);
                        backtracking(nums, branch);
                        branch[i] = false;
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> permute(vector<int>& nums)
        {
                vector<bool> branch(nums.size(), false);
                backtracking(nums, branch);
                return results;
        }
};

int main()
{
        return 0;
}