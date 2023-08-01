/*
* 刷题统计
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll workCal(ll a, ll b, ll n)
{
		ll a_week_work = 5 * a + 2 * b;
		ll bigwork = 7 * n / a_week_work;
		if (n % a_week_work == 0) return bigwork;
		else
		{
				ll littlework = n % a_week_work;
				if (littlework > 5 * a + b) return bigwork + 7;
				else if (littlework > 5 * a) return bigwork + 6;
				else
				{
						int count = 0;
						while (littlework > 0)
						{
								littlework -= a;
								++count;
						}
						return bigwork + count;
				}
		}
}

int main()
{
		// 工作日刷a道题，周末刷b道题，问第几天能够做到不小于n题
		ll a = 10, b = 20, n = 99;
		// cin >> a >> b >> n;
		cout << workCal(a, b, n) << endl;
		return 0;
}