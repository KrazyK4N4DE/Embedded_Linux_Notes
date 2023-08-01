/*
* 组合总和Ⅱ
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
        void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used)
        {
                if (sum > target) return;
                if (sum == target)
                {
                        results.push_back(path);
                        return;
                }
                for (int i = startIndex; i < candidates.size(); i++)
                {
                        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;  // candidates[i] == candidates[i - 1] && use[i - 1] == false表示前一个相等的数没有被使用，则需要树层去重
                        path.push_back(candidates[i]);
                        sum += candidates[i];
                        used[i] = true;
                        backtracking(candidates, target, sum, i + 1, used);
                        used[i] = false;
                        sum -= candidates[i];
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
        {
                sort(candidates.begin(), candidates.end());
                vector<bool> used(candidates.size(), false);
                backtracking(candidates, target, 0, 0, used);
                return results;
        }
};

int main()
{
        return 0;
}