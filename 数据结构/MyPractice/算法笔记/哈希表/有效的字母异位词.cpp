/*
* 有效的字母异位词(LeetCode242)
*/
#include <iostream>
using namespace std;

bool isAnagram(string s, string t)
{
		int hash[26] = { 0 };
		for (int i = 0; i < s.size(); i++)  // 统计s字符串，字符相应下标作出现++计数
				hash[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++)  // 统计t字符串，字符相应下标作出现--计数
				hash[t[i] - 'a']--;
		for (int i = 0; i < 26; i++)  // 若哈希表里有任意元素不等于0时，表明两字符串中某字符出现次数不一
				if (hash[i] != 0) return false;
		return true;
}

int main()
{
		return 0;
}