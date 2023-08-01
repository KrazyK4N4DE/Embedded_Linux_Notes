/*
* 子集
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
        vector<vector<int>> results;
        vector<int> path;
        void backtracking(vector<int>& nums, int startIndex)
        {
                if (startIndex == nums.size()) return;
                for (int i = startIndex; i < nums.size(); i++)
                {
                        path.push_back(nums[i]);
                        results.push_back(path);
                        backtracking(nums, i + 1);
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> subsets(vector<int>& nums)
        {
                results.push_back(path);  // 先压入一个空数组
                backtracking(nums, 0);
                return results;
        }
};

int main()
{
		return 0;
}