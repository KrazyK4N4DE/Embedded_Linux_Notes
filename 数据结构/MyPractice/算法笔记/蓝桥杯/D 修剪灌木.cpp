/*
* �޼���ľ
* ��ʵ�����㵱ǰԪ�ص� max(����Ԫ�ص�λ������, ��ĩβԪ��λ�õ�����)
*/
#include <iostream>
using namespace std;

void printBushHeight(int n)
{
		int start = 0, end = n - 1;  // ��¼������Զλ��
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