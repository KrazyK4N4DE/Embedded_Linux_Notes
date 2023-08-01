/*
* ����������
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
        void backtracking(vector<int>& nums, int startIndex)  // û����used��ȥ�أ���Ϊ���鲻�ܽ�������
        {
                if (path.size() > 1) results.push_back(path);  // ��Ŀ˵�ˣ�����������������
                unordered_set<int> uset;
                for (int i = startIndex; i < nums.size(); i++)
                {
                        if (!path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) continue;
                        uset.insert(nums[i]);  // uset���û��ݣ���Ϊÿ�ݹ�һ�Σ������½�һ���ֲ�uset��ֻ���¼�����Ƿ����ظ�����
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