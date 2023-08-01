/*
* 电话号码的字母组合
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
private:
        string letterMap[10] =
        {
                " ",
                " ",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz"
        };
        vector<string> results;
        string path;
        void backtracking(string digits, int index)  // 不同于startIndex，index是告诉程序，传入的digits数组遍历到哪个下标了
        {
                if (digits.size() == 0) return;
                if (index == digits.size())
                {
                        results.push_back(path);
                        return;
                }

                int digit = digits[index] - '0';  // 字符转化为数字
                string letter = letterMap[digit];  // 从字符串中取出对应位置的数字，然后对应数字再映射到相应的字母表中

                for (int i = 0; i < letter.size(); i++)  // 遍历的范围就是树的宽度，这里指每个数字对应字母数组的大小为范围
                {
                        path.push_back(letter[i]);
                        backtracking(digits, index + 1);
                        path.pop_back();
                }
        }
public:
        vector<string> letterCombinations(string digits) 
        {
                backtracking(digits, 0);
                return results;
        }
};