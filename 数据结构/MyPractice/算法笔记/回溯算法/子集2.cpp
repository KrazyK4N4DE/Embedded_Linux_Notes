/*
* ×Ó¼¯¢ò
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
        void backtracking(vector<int>& nums, int startIndex, vector<bool>& used)
        {
                if (startIndex == nums.size()) return;
                for (int i = startIndex; i < nums.size(); i++)
                {
                        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
                        path.push_back(nums[i]);
                        results.push_back(path);
                        used[i] = true;
                        backtracking(nums, i + 1, used);
                        used[i] = false;
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) 
        {
                sort(nums.begin(), nums.end());
                vector<bool> used(nums.size(), false);
                results.push_back(path);
                backtracking(nums, 0, used);
                return results;
        }
};

int main()
{
		return 0;
}