/*
* 等差子数组
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
{
		vector<bool> result;

		auto check = [](vector<int>& nums, int l, int r)
		{
				unordered_set<int> set;
				int n = r - l + 1;
				int a1 = INT_MAX, an = INT_MIN;
				for (int i = l; i <= r; i++)
				{
						set.insert(nums[i]);
						a1 = min(a1, nums[i]);
						an = max(an, nums[i]);
				}
				if ((an - a1) % (n - 1)) return false;
				int d = (an - a1) / (n - 1);
				for (int i = 1; i < n; i++)
						if (!set.count(a1 + (i - 1) * d)) return false;
				return true;
		};

		for (int i = 0; i < l.size(); i++)
		{
				result.push_back(check(nums, l[i], r[i]));
		}
		return result;
}

int main()
{

}