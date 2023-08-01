/*
* F 时间显示
* 给定一个毫秒数(假定从1970年0时0分0秒到现在)，让其转换为现在的时分秒
*/
#include <iostream>
using namespace std;

const int DAY_SECOND = 24 * 60 * 60;
typedef long long LL;

int main()
{
		LL n;
		cin >> n;

		n /= 1000;  // 把秒以下的单位去掉，因为用不到
		n %= DAY_SECOND;  // 只剩今天的时间
		
		int h = n / 3600;
		n %= 3600;
		int m = n / 60;
		int s = n % 60;

		printf("%02d:%02d:%02d", h, m, s);

		return 0;
}