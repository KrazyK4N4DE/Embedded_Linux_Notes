/*
* 组合问题：使用回溯算法
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
        vector<vector<int>> results;  // 二维数组，放所有k大小的数组
        vector<int> path;  // 一维数组，用于存放单个递归中k大小的数组
        void backtracking(int n, int k, int startIndex)
        {
                if (path.size() == k)
                {
                        results.push_back(path);
                        return;
                }
                for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)  // i的范围做了剪枝优化
                {
                        path.push_back(i);
                        backtracking(n, k, i + 1);
                        path.pop_back();
                }
        }

public:
        vector<vector<int>> combine(int n, int k)
        {
                backtracking(n, k, 1);
                return results;
        }
};

int main()
{
		return 0;
}