/*
* 反转字符串Ⅱ
*/
#include <iostream>
#include <vector>
using namespace std;

// 反转指定数量的字符串
void reverse(string& s, int start, int end)
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

string reverseStr(string s, int k)
{
		string str = s;
		for (int i = 0; i < str.size(); i += (2 * k))  // 为什么要加2k而不是i++？因为单次处理判断的就是2k个字符
		{
				if (i + k <= str.size())  // 为什么要有等号？在下面的reverse函数中是左闭右开的，即i + k的位置不算在翻转中，所以可以等于
				{
						reverse(str, i, i + k);
						continue;
				}
				reverse(str, i, str.size());
		}
		return str;
}

int main()
{
		return 0;
}