/*
* ����ܺ͢�
* �ѵ㣺��ֹ���������ݲ�������֦
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
        vector<vector<int>> results;
        vector<int> path;
        void backtracking(int k, int n, int sum, int startIndex)
        {
                if (sum > n) return;  // ��֦����1
                if (path.size() == k)
                {
                        if (sum == n)
                                results.push_back(path);
                        return;
                }
                for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)  // ��֦����2
                {
                        sum += i;
                        path.push_back(i);
                        backtracking(k, n, sum, i + 1);
                        sum -= i;  // ��i����ȥ���ݵ������
                        path.pop_back();
                }
        }
public:
        vector<vector<int>> combinationSum3(int k, int n) 
        {
                int sum = 0;
                backtracking(k, n, sum, 1);
                return results;
        }
};