#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
		string main_str, secondary_str;
		bool flag = 0;
		cout << "输入主串: ";
		getline(cin, main_str);
		cout << "输入子串: ";
		getline(cin, secondary_str);
		for (int i = 0; i < main_str.length(); ++i)
		{
				flag = 0;
				for (int j = 0; j < secondary_str.length(); ++j)
				{
						if (main_str[i + j] != secondary_str[j])
						{
								flag = 1;
								break;
						}
				}
				if (!flag) break;
		}
		cout << (flag ? "不包含" : "包含") << endl;

		return 0;
}