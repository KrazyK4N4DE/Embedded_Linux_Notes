/*
* B ��Ƭ
*/
#include <iostream>
using namespace std;

int s[10];  // 0��9�Ŀ�Ƭ���Եĸ���

bool check(int x)
{
		while (x)
		{
				int tmp = x % 10;
				x /= 10;
				if (s[tmp]-- <= 0) return false;
		}
		return true;
}

int main()
{
		for (int index = 0; index < 10; ++index)
		{
				s[index] = 2021;
		}

		int i = 1;
		while (i)
		{
				if (!check(i))
				{
						cout << i - 1 << endl;
						return 0;
				}
				++i;
		}

		return 0;
}