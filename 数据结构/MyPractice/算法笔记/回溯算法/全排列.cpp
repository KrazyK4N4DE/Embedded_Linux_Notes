/*
* ȫ����
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
                for (int i = 0; i < nums.size(); i++)  // i��0��ʼ������startIndex������Ϊ�����Ԫ������һ����˳��һ��Ҳ��ͬһ���������ϲ����һ�α���Ҫ�ų���֮ǰ��
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