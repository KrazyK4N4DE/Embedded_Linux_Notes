/*
* 反转字符串中的单词
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 反转指定数量的字符串
void reverseWord(string& s, int start, int end)
{
		int left = start, right = end - 1;
		while (left < right)
		{
				char tmp = s[left];
				s[left] = s[right];
				s[right] = tmp;
				left++;
				right--;
		}
}

string reverseWords(string s)
{
		// 快慢双指针移除空格
		int slow = 0;
		for (int fast = 0; fast < s.size(); fast++)
		{
				// 先把程序放入大的if循环中，再进行分步处理
				if (s[fast] != ' ')
				{
						if (slow != 0) s[slow++] = ' ';  // 保证每个单词之间都有一个空格(句首除外)
						while (fast < s.size() && s[fast] != ' ')  // 把fast遍历到的单个单词逐一字符连续赋给slow
						{
								s[slow] = s[fast];
								fast++;
								slow++;
						}
				}
		}
		s.resize(slow);
		// 字符串全部反转
		reverse(s.begin(), s.end());
		// 单词逐个反转
		for (int start = 0, i = 0; i <= s.size(); i++)  // 需要<=，因为最后一个单词也需要反转
		{
				if (i == s.size() || s[i] == ' ')
				{
						reverseWord(s, start, i);
						start = i + 1;
				}
		}
		return s;
}

int main()
{
		return 0;
}