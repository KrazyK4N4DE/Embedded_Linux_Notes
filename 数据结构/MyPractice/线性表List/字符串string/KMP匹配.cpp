/*
字符串KMP匹配算法
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
		string str1 = "abababdbababcdabcc";
		string str2 = "ababc";
		int len1 = str1.length();
		int len2 = str2.length();
		int* next = new int[len2];

		// 为next数组计算值
		next[0] = 0;
		for (int i = 1; i < len2; ++i)
		{
				int j = i - 1;  // 临时变量用于调用next数组的
				while (1)
				{
						if (next[j] == 0 || str2[i - 1] == str2[next[j] - 1])
						{
								next[i] = next[j] + 1;  // 找到相等的字符，就可以加1了
								break;
						}
						j = next[j] - 1;  // 字符不匹配的话，就改变 j 值，找另一个位置 i 之前的字符
				}
		}

		// 开始匹配
		int i = 0, j = 0;
		while (i < len1)
		{
				if (str1[i] == str2[j])
				{
						++i;
						++j;
				}
				else
				{
						if (j == 0)
								++i;
						else  // 子串匹配中途中断时
								j = next[j] - 1;  // 跳动到前面的位置，由于之前next数组的计算，可以省略一些不必要再进行的匹配(比如相同的字符)
				}
				if (j == len2) break;
		}

		cout << ((j == len2) ? "匹配" : "不匹配") << endl;

		return 0;
}