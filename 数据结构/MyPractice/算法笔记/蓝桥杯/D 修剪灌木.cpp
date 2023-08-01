/*
* 修剪灌木
* 其实就是算当前元素的 max(到首元素的位置来回, 到末尾元素位置的来回)
*/
#include <iostream>
using namespace std;

void printBushHeight(int n)
{
		int start = 0, end = n - 1;  // 记录左右最远位置
		for (int i = 0; i < n; ++i)
		{
				printf("%d\n", 2 * max(i - start, end - i));
		}
}

int main()
{
		int n;
		cin >> n;
		printBushHeight(n);

		return 0;
}