/*
С���õ���һ������Ϊ n �����顣����������ġ�����ֵ��Ϊ��������֮��ľ���ֵ֮�͡�
���磬��������[1,3,1,4,2] ���ԣ��䶸��ֵΪ|1-3| + |3-1l + |1-4| + |4-2| =2+2+3+2=9��
����С�춨��f(i)Ϊ: ֻ�޸ĵ�i��Ԫ�ص�����£�������Դ�ɵ���С½��ֵ�������������1<=i<=n��ÿ��f(i)��ֵ��

����������
��һ��һ��������n����������ĳ��ȡ�
�ڶ�������n��������ai������С���õ������顣
1<=n<=10e5
1<=ai<=10e9

���������
һ�����n����������i����������f(i)��ֵ��

ʾ��1��

���룺
3
1 2 1

�����
1 0 1
*/

#include <iostream>
using namespace std;

// ���ڷǾ���ֵ��������
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

// ���ھ���ֵ��������
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
		// ����
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
		// ����ֵ����
		int* steep = new int[n + 1];
		int total = 0;
		for (int i = 1; i < n; ++i)
		{
				// ����Ԫ�طǾ���ֵ�汾
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
		// ����ֵ����
		int* steep = new int[n + 1];
		int total = 0;
		for (int i = 1; i < n; ++i)
		{
				// ����Ԫ�ؾ���ֵ�汾
				steep[i] = abs(a[i - 1] - a[i]);
				total += steep[i];
		}
		steep[0] = 0;
		steep[n] = 0;

		cal_steep_total(n, steep, total);

		return 0;
}