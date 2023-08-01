/*
* 重复的子字符串
*/
#include <iostream>
using namespace std;

// 移动匹配：既然前面有相同的子串，后面有相同的子串，用 s + s，这样组成的字符串中，后面的子串做前串，前后的子串做后串，就一定还能组成一个s
bool repeatedSubstringPattern(string s)
{
        string ss = s + s;  // 两个字符串拼接起来
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);  // 掐头去尾
        if (ss.find(s) != string::npos) return true;  // 如果掐头去尾后还能找到s字符串，说明拼接后又出现个s
        return false;
}

// KMP算法：最长相等前后缀不包含的这个子串就是最小重复子串
void getNext(int* next, const string& s)
{
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
                while (j > 0 && s[j] != s[i]) j = next[j - 1];
                if (s[j] == s[i]) j++;
                next[i] = j;
        }
}
bool repeatedSubstringPatternKMP(string s)
{
        int len = s.size();
        if (len == 0) return false;  // 字符串长度为0，根本没有内容，别谈子串了
        int* next = new int[len];
        getNext(next, s);  // 构造前缀表
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) return true;  // len - next[len - 1]表示最长相等前后缀不包含的子串的长度，如果不能被len整除，那肯定不是重复子串了
        return false;
}

int main()
{
		return 0;
}