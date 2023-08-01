/*
* 分发饼干
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
		// 自己做出来的版本，属于尽量用小饼干满足胃口，有点久
		int findContentChildren_self(vector<int>& g, vector<int>& s)
		{
				sort(g.begin(), g.end());
				sort(s.begin(), s.end());
				int count = 0;
				for (int i = 0; i < g.size(); i++)
				{
						for (int j = 0; j < s.size(); j++)
						{
								if (s[j] >= g[i])
								{
										count++;
										s[j] = 0;
										g[i] = INT_MAX;
								}
						}
				}
				return count;
		}

		// 代码随想录版本，尽量用大饼干满足胃口
		int findContentChildren(vector<int>& g, vector<int>& s)
		{
				sort(g.begin(), g.end());
				sort(s.begin(), s.end());
				int count = 0;
				int index = s.size();
				for (int i = g.size() - 1; i >= 0; i--)
				{
						while (index >= 0 && s[index] >= g[i])
						{
								count++;
								index--;
								break;
						}
				}
				return count;
		}
		// 代码随想录版本，尽量用小饼干满足胃口
		int findContentChildren2(vector<int>& g, vector<int>& s) {
				sort(g.begin(), g.end());
				sort(s.begin(), s.end());
				int index = 0;
				for (int i = 0; i < s.size(); ++i) {
						if (index < g.size() && g[index] <= s[i]) {
								index++;
						}
				}
				return index;
		}
};

int main()
{
		return 0;
}