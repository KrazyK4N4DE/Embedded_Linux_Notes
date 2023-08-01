/**
* ʹ�ö�̬�滮���쳲�������������
*/
#include <iostream>
using namespace std;

inline int Fibonacci(int n)
{
		if (n < 2) return 1;
		int* dp = new int[n + 1];  // n�Ľ׳���Ҫn + 1��λ�ã���Ϊ����0�Ľ׳�
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; ++i)
				dp[i] = dp[i - 1] + dp[i - 2];  // ���ƹ�ʽ
		int total = dp[n];
		delete[] dp;
		return total;
}
/*�����*/
inline int FibonacciBetter(int n)
{
		int sum = 1;
		if (n < 2) return sum;
		int dp[2] = {1, 1};
		for (int i = 2; i <= n; ++i)
		{
				sum = dp[0] + dp[1];
				dp[0] = dp[1];
				dp[1] = sum;
		}
		return sum;
}

int  main()
{
		int n;
		cout << "����ڼ������У�";
		cin >> n;
		
		cout << "���Ϊ��" << Fibonacci(n) << endl;
		cout << "���Ϊ��" << FibonacciBetter(n) << endl;

		return 0;
}