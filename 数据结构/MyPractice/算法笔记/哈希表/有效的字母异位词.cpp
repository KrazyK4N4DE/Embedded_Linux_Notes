/*
* ��Ч����ĸ��λ��(LeetCode242)
*/
#include <iostream>
using namespace std;

bool isAnagram(string s, string t)
{
		int hash[26] = { 0 };
		for (int i = 0; i < s.size(); i++)  // ͳ��s�ַ������ַ���Ӧ�±�������++����
				hash[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++)  // ͳ��t�ַ������ַ���Ӧ�±�������--����
				hash[t[i] - 'a']--;
		for (int i = 0; i < 26; i++)  // ����ϣ����������Ԫ�ز�����0ʱ���������ַ�����ĳ�ַ����ִ�����һ
				if (hash[i] != 0) return false;
		return true;
}

int main()
{
		return 0;
}