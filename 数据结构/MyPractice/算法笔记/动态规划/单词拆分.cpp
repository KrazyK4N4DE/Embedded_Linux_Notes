/*
* 单词拆分：能否装满背包的问题
* 难点：递推公式，遍历顺序
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for(int i = 1; i <= s.size(); i++)
				for (int j = 0; j < i; j++)
				{
						string word = s.substr(j, i - j);
						if (wordSet.find(word) != wordSet.end() && dp[j] == true) dp[i] = true;
				}
		return dp[s.size()];
}

int main()
{
		return 0;
}