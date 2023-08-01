/*
�ַ���KMPƥ���㷨
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

		// Ϊnext�������ֵ
		next[0] = 0;
		for (int i = 1; i < len2; ++i)
		{
				int j = i - 1;  // ��ʱ�������ڵ���next�����
				while (1)
				{
						if (next[j] == 0 || str2[i - 1] == str2[next[j] - 1])
						{
								next[i] = next[j] + 1;  // �ҵ���ȵ��ַ����Ϳ��Լ�1��
								break;
						}
						j = next[j] - 1;  // �ַ���ƥ��Ļ����͸ı� j ֵ������һ��λ�� i ֮ǰ���ַ�
				}
		}

		// ��ʼƥ��
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
						else  // �Ӵ�ƥ����;�ж�ʱ
								j = next[j] - 1;  // ������ǰ���λ�ã�����֮ǰnext����ļ��㣬����ʡ��һЩ����Ҫ�ٽ��е�ƥ��(������ͬ���ַ�)
				}
				if (j == len2) break;
		}

		cout << ((j == len2) ? "ƥ��" : "��ƥ��") << endl;

		return 0;
}