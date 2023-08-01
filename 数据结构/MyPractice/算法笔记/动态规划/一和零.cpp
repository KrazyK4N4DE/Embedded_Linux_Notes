/*
* һ���㣺װ����������ж�����Ʒ
�ѵ㣺����˳��
*/
#include <iostream>
#include<vector>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
		// ��ʼ����
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (string str : strs)  // ������Ʒ
		{
				int x = 0, y = 0;  // ��¼�����ַ���0��1�ĸ���
				for (char c : str)
				{
						if (c == '0') x++;
						else y++;
				}
				// ��������������ά�ȣ�����ѭ����Ҫ�������
				for (int i = m; i >= x; i--)
						for (int j = n; j >= y; j--)
								dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
		}
		return dp[m][n];
}

int main()
{
		return 0;
}