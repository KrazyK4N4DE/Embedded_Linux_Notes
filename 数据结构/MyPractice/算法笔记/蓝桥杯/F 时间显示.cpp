/*
* F ʱ����ʾ
* ����һ��������(�ٶ���1970��0ʱ0��0�뵽����)������ת��Ϊ���ڵ�ʱ����
*/
#include <iostream>
using namespace std;

const int DAY_SECOND = 24 * 60 * 60;
typedef long long LL;

int main()
{
		LL n;
		cin >> n;

		n /= 1000;  // �������µĵ�λȥ������Ϊ�ò���
		n %= DAY_SECOND;  // ֻʣ�����ʱ��
		
		int h = n / 3600;
		n %= 3600;
		int m = n / 60;
		int s = n % 60;

		printf("%02d:%02d:%02d", h, m, s);

		return 0;
}