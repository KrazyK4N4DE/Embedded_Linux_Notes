/*
* ��ת�ַ�����
*/
#include <iostream>
#include <vector>
using namespace std;

// ��תָ���������ַ���
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
		for (int i = 0; i < str.size(); i += (2 * k))  // ΪʲôҪ��2k������i++����Ϊ���δ����жϵľ���2k���ַ�
		{
				if (i + k <= str.size())  // ΪʲôҪ�еȺţ��������reverse������������ҿ��ģ���i + k��λ�ò����ڷ�ת�У����Կ��Ե���
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