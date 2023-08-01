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
		// 输入环节
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

		// 因为 a >= b，所以ma >= mb，当ma > mb时，要对mb进行移位，保证位是对应的
		while (a.size() != b.size())
		{
				b.insert(b.begin(), 0);
		}
		ll ans = 0;
		for (int i = 0; i < ma - 1; i++) {
				ans = ((ans + a[i] - b[i]) * max(max(a[i + 1] + 1, 2), max(b[i + 1] + 1, 2))) % MOD;  // max(a[i], b[i]) + 1表示两个同一位的数最低能用哪位表示。后面还要和二进制比较
		}
		ans = (ans + a[ma - 1] - b[ma - 1]) % MOD;
		cout << ans;
		return 0;
}