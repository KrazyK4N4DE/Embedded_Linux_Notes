/*
* �Թ�
* DFS + ���
*/
#include <iostream>
using namespace std;

// �Թ�
string palace[10] =
{
		"UDDLUULRUL",
		"UURLLLRRRU",
		"RRUURLDLRD",
		"RUDDDDUUUU",
		"URUDLLRRUU",
		"DURLRLDLRL",
		"ULLURLLRDU",
		"RDLULLRDDD",
		"UUDDUDUDLL",
		"ULRDLUURRR"
};
// �������
bool flags[10][10] = { 0 };

bool dfs(int i, int j)
{
		if (i < 0 || j < 0 || i > 9 || j > 9) return true;
		if (flags[i][j] == 1) return false;  // �ܻ�ԭ·�ģ�������ѭ�����߲���ȥ
		flags[i][j] = 1;  // ��ǰλ�ñ��Ϊ1
		switch (palace[i][j])
		{
		case 'U':
				return dfs(i - 1, j);
		case 'D':
				return dfs(i + 1, j);
		case 'L':
				return dfs(i, j - 1);
		case 'R':
				return dfs(i, j + 1);
		default:
				return false;
		}
}

int main()
{
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
				for (int j = 0; j < 10; j++)
				{
						memset(flags, 0, sizeof(flags));
						if (dfs(i, j)) count++;
				}
		}
		cout << count << endl;

		return 0;
}