/*
* D »õÎï°Ú·Å
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int main()
{
		LL n;
		cin >> n;
		vector<LL> len;
		for(LL i = 1; i * i <= n; ++i)
				if (n % i == 0)
				{
						len.push_back(i);
						if (n / i != i) len.push_back(n / i);
				}
		int count = 0;
		for(auto a : len)
				for(auto b : len)
						for (auto c : len)
								if (a * b * c == n) ++count;
		cout << count << endl;

		return 0;
}