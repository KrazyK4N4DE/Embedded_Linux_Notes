/*
小红拿到了一个长度为 n 的数组。她定义数组的“陡峭值”为相邻两数之差的绝对值之和。
例如，对于数组[1,3,1,4,2] 而言，其陡峭值为|1-3| + |3-1l + |1-4| + |4-2| =2+2+3+2=9。
现在小红定义f(i)为: 只修改第i个元素的情况下，数组可以达成的最小陆峭值。请你输出对于1<=i<=n，每个f(i)的值。

输入描述：
第一行一个正整数n。代表数组的长度。
第二行输入n个正整数ai，代表小红拿到的数组。
1<=n<=10e5
1<=ai<=10e9

输出描述：
一行输出n个整数，第i个整数代表f(i)的值。

示例1：

输入：
3
1 2 1

输出：
1 0 1
*/

#include <iostream>
using namespace std;

// 用于非绝对值陡峭数组
void cal_steep(const int* arr, int n, const int* st)
{
		int* tmp = new int[n];
		for (int i = 0; i < n; ++i) tmp[i] = arr[i];
		for (int i = 0; i < n; ++i)
		{
				tmp[i] = arr[i] + (st[i] - st[i + 1]) / 2;
				int tmptotal = 0;
				for (int j = 1; j < n; ++j)
				{
						int tmpi = abs(tmp[j - 1] - tmp[j]);
						tmptotal += tmpi;
				}
				cout << tmptotal << " ";
				tmp[i] = arr[i];
		}
		cout << endl;
}

// 用于绝对值陡峭数组
void cal_steep_total(int n, const int* st, int total)
{
		for (int i = 0; i < n; ++i)
		{
				int tmp = st[i] + st[i + 1];
				cout << total - (tmp - (tmp % 2)) << " ";
		}
		cout << endl;
}

int main()
{
		// 输入
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i)
		{
				cin >> a[i];
		}
		/*
		for (int i = 0; i < n; ++i)
		{
				cout << a[i] << " ";
		}
		cout << endl;
		// 陡峭值数组
		int* steep = new int[n + 1];
		int total = 0;
		for (int i = 1; i < n; ++i)
		{
				// 数组元素非绝对值版本
				steep[i] = a[i - 1] - a[i];
				total += abs(steep[i]);
		}
		steep[0] = -steep[1];
		steep[n] = -steep[n - 1];
		for (int i = 0; i < n + 1; ++i)
		{
				cout << steep[i] << " ";
		}
		cout << endl;
		cout << total << endl;
		*/
		// 陡峭值数组
		int* steep = new int[n + 1];
		int total = 0;
		for (int i = 1; i < n; ++i)
		{
				// 数组元素绝对值版本
				steep[i] = abs(a[i - 1] - a[i]);
				total += steep[i];
		}
		steep[0] = 0;
		steep[n] = 0;

		cal_steep_total(n, steep, total);

		return 0;
}