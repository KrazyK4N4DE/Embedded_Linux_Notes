/*
* ������⣺ʹ�û����㷨
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
        vector<vector<int>> results;  // ��ά���飬������k��С������
        vector<int> path;  // һά���飬���ڴ�ŵ����ݹ���k��С������
        void backtracking(int n, int k, int startIndex)
        {
                if (path.size() == k)
                {
                        results.push_back(path);
                        return;
                }
                for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)  // i�ķ�Χ���˼�֦�Ż�
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