/**
* ��¥�ݣ���1�׿�ʼ�Ƶ�������쳲��������У��ö�̬�滮
* �ѵ㣺�Ƴ����ƹ�ʽ
*/
#include <iostream>
using namespace std;

int Stair(int n)
{
		if (n < 3) return n;
		int sum = 0;
		int dp[3] = { 0, 1, 2};
		for (int i = 3; i <= n; ++i)
		{
				sum = dp[1] + dp[2];
				dp[1] = dp[2];
				dp[2] = sum;
		}
		return sum;
}

int main()
{
		int n;
		cout << "���������";
		cin >> n;
		cout << "���Ϊ��" << Stair(n) << endl;

		return 0;
}