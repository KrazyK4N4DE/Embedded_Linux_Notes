/*
* È«ÅÅÁÐ¢ò
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
        vector<vector<int>> results;
        vector<int> path;
        void backtracking(vector<int>& nums, vector<bool>& used)
        {
                if (path.size() == nums.size())
                {
                        results.push_back(path);
                        return;
                }
                for (int i = 0; i < nums.size(); i++)
                {
                        if (used[i] == true || (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)) continue;
                        used[i] = true;
                        path.push_back(nums[i]);
                        backtracking(nums, used);
                        used[i] = false;
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
                sort(nums.begin(), nums.end());
                vector<bool> used(nums.size(), false);
                backtracking(nums, used);
                return results;
        }
};

int main()
{
        return 0;
}