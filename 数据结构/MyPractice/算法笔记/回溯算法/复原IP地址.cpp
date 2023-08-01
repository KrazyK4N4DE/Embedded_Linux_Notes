/*
* 复原IP地址
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
        bool isValid(const string& s, int start, int end)
        {
                if (start > end) return false;  // 没有一点东西
                if (s[start] == '0' && start != end) return false;  // 不是纯0，但是有前导0
                int num = 0;
                for (int i = start; i <= end; i++)  // 字符串转数字
                {
                        if (s[i] > '9' || s[i] < '0') return false;  // 不是0到9，非法
                        num = num * 10 + (s[i] - '0');
                        if (num > 255) return false;  // 转换后的数大于255，不符合我对ip的想象
                }
                return true;
        }

        vector<string> results;
        void backtracking(string s, int startIndex, int pointNum)
        {
                if (pointNum == 3)
                {
                        if (isValid(s, startIndex, s.size() - 1))
                                results.push_back(s);
                        return;
                }
                for (int i = startIndex; i < s.size(); i++)
                {
                        if (isValid(s, startIndex, i))
                        {
                                s.insert(s.begin() + i + 1, '.');  // +1是因为小数点要放在i位置的数字后面
                                pointNum++;
                                backtracking(s, i + 2, pointNum);  // 因为字符串插入了一个小数点，所以不是+1是+2
                                pointNum--;
                                s.erase(s.begin() + i + 1);
                        }
                        else break;  //子串不符合条件，这一层的横向遍历都不需要了，因为已经知道这是个无效的IP
                }
        }
public:
        vector<string> restoreIpAddresses(string s) {
                if (s.size() < 4 || s.size() > 12) return results;  // 浅浅剪枝一下
                backtracking(s, 0, 0);
                return results;
        }
};

int main()
{
        return 0;
}