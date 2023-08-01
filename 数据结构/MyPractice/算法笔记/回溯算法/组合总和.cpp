/*
* 组合总和
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
		vector<vector<int>> results;
		vector<int> path;
		void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
		{
				if (sum > target) return;
				if (sum == target)
				{
						results.push_back(path);
						return;
				}
				for (int i = startIndex; i < candidates.size(); i++)
				{
						path.push_back(candidates[i]);
						sum += candidates[i];
						backtracking(candidates, target, sum, i);  // 因为同一数字可以无限制重复选取，所以不是i + 1
						sum -= candidates[i];
						path.pop_back();
				}
		}
public:
		// 快速排序
		void quicksort(vector<int>& arr, int start, int end)
		{
				if (start >= end) return;
				int left = start, right = end, pivot = arr[left];
				// 从右往左看，直到遇到比基准小的，就扔到基准左边
				while (left < right && arr[right] >= pivot) right--;
				arr[left] = arr[right];
				// 从左往右看，知道遇到比基准大的，就扔到基准右边
				while (left < right && arr[left] <= pivot) left++;
				arr[right] = arr[left];

				arr[left] = pivot;

				quicksort(arr, start, left - 1);
				quicksort(arr, left + 1, end);
		}

		vector<vector<int>> combinationSum(vector<int>& candidates, int target)
		{
				int sum = 0;
				quicksort(candidates, 0, candidates.size() - 1);
				backtracking(candidates, target, sum, 0);
				return results;
		}
};