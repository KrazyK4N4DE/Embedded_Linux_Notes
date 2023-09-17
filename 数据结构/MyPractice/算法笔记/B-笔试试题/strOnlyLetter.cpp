#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 去除字符串中的重复字母
string removeDuplicates(const string& str) {
        string result;
        unordered_set<char> seen;

        for (char ch : str) {
                if (seen.find(ch) == seen.end()) {
                        result += ch;
                        seen.insert(ch);
                }
        }

        return result;
}

bool areStringsEqual(const string& str1, const string& str2) {
        // 首先，将两个字符串去重后再排序以确保它们包含相同的字母
        string sortedStr1 = removeDuplicates(str1);
        string sortedStr2 = removeDuplicates(str2);

        sort(sortedStr1.begin(), sortedStr1.end());
        sort(sortedStr2.begin(), sortedStr2.end());

        // 比较排序后的字符串是否相等
        return sortedStr1 == sortedStr2;
}

int main() {
        string str1, str2;

        // 输入两个字符串
        cout << "请输入第一个字符串：";
        cin >> str1;
        cout << "请输入第二个字符串：";
        cin >> str2;

        // 检查两个字符串是否仅包含相同的字母并输出结果
        cout << (areStringsEqual(str1, str2) ? "true" : "false") << endl;

        return 0;
}
