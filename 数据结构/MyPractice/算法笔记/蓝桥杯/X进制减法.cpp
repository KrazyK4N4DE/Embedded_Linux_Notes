#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
vector<int> a, b;
int main()
{
		// ���뻷��
		cin >> n;
		int ma, mb;
		cin >> ma;
		int num;
		for (int i = 0; i < ma; i++) {
				cin >> num;
				a.push_back(num);
		}
		cin >> mb;
		for (int i = 0; i < mb; i++) {
				cin >> num;
				b.push_back(num);
		}

		// ��Ϊ a >= b������ma >= mb����ma > mbʱ��Ҫ��mb������λ����֤λ�Ƕ�Ӧ��
		while (a.size() != b.size())
		{
				b.insert(b.begin(), 0);
		}
		ll ans = 0;
		for (int i = 0; i < ma - 1; i++) {
				ans = ((ans + a[i] - b[i]) * max(max(a[i + 1] + 1, 2), max(b[i + 1] + 1, 2))) % MOD;  // max(a[i], b[i]) + 1��ʾ����ͬһλ�������������λ��ʾ�����滹Ҫ�Ͷ����ƱȽ�
		}
		ans = (ans + a[ma - 1] - b[ma - 1]) % MOD;
		cout << ans;
		return 0;
}