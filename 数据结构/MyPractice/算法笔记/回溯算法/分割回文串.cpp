/*
* 分割回文串
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
        // 判断是否为回文串(双指针)
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
                if (startIndex == s.length())  // 切割到最后面就结束，判断最近的子串是否为回文串的操作放在递归逻辑中了
                {
                        results.push_back(path);
                        return;
                }
                for (int i = startIndex; i < s.length(); i++)
                {
                        if (isPalindrome(s, startIndex, i))  // 要切割的子串是回文串的话就压入path中
                        {
                                string str = s.substr(startIndex, i - startIndex + 1);
                                path.push_back(str);
                        }
                        else  // 刚处理的子串不是回文串的话，就没必要递归下去了
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