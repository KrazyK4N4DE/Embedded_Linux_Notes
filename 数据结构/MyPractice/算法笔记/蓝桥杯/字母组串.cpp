/*
* 字母组串
*/
#include <iostream>
using namespace std;

//  a个A，b个B，c个C 字母，能组成多少个不同的长度为n的字符串
int f(int a, int b, int c, int n)
{
		if (a < 0 || b < 0 || c < 0) return 0;  // 剪枝
		if (n == 0) return 1;  // n个字母用完了，即表示组成了长度为n的字符串
		return f(a - 1, b, c, n - 1) + f(a, b - 1, c, n - 1) + f(a, b, c - 1, n - 1);
}

int main()
{
		cout << f(1, 1, 1, 2) << endl;
		cout << f(1, 2, 3, 3) << endl;
		return 0;
}