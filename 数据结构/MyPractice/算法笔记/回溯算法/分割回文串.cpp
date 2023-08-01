/*
* �ָ���Ĵ�
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
        // �ж��Ƿ�Ϊ���Ĵ�(˫ָ��)
        bool isPalindrome(const string& s, int start, int end)
        {
                for (; start < end; start++, end--)
                        if (s[start] != s[end])
                                return false;
                return true;
        }
        vector<vector<string>> results;
        vector<string> path;
        void backtracking(string s, int startIndex)
        {
                if (startIndex == s.length())  // �и�����ͽ������ж�������Ӵ��Ƿ�Ϊ���Ĵ��Ĳ������ڵݹ��߼�����
                {
                        results.push_back(path);
                        return;
                }
                for (int i = startIndex; i < s.length(); i++)
                {
                        if (isPalindrome(s, startIndex, i))  // Ҫ�и���Ӵ��ǻ��Ĵ��Ļ���ѹ��path��
                        {
                                string str = s.substr(startIndex, i - startIndex + 1);
                                path.push_back(str);
                        }
                        else  // �մ�����Ӵ����ǻ��Ĵ��Ļ�����û��Ҫ�ݹ���ȥ��
                                continue;
                        backtracking(s, i + 1);
                        path.pop_back();
                }
        }
public:
        vector<vector<string>> partition(string s) 
        {
                backtracking(s, 0);
                return results;
        }
};

int main()
{
        return 0;
}