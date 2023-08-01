/*
* ��ת�ַ����еĵ���
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��תָ���������ַ���
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
		// ����˫ָ���Ƴ��ո�
		int slow = 0;
		for (int fast = 0; fast < s.size(); fast++)
		{
				// �Ȱѳ��������ifѭ���У��ٽ��зֲ�����
				if (s[fast] != ' ')
				{
						if (slow != 0) s[slow++] = ' ';  // ��֤ÿ������֮�䶼��һ���ո�(���׳���)
						while (fast < s.size() && s[fast] != ' ')  // ��fast�������ĵ���������һ�ַ���������slow
						{
								s[slow] = s[fast];
								fast++;
								slow++;
						}
				}
		}
		s.resize(slow);
		// �ַ���ȫ����ת
		reverse(s.begin(), s.end());
		// ���������ת
		for (int start = 0, i = 0; i <= s.size(); i++)  // ��Ҫ<=����Ϊ���һ������Ҳ��Ҫ��ת
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