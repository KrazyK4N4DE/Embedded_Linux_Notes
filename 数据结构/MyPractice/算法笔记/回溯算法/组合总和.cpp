/*
* ����ܺ�
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
						backtracking(candidates, target, sum, i);  // ��Ϊͬһ���ֿ����������ظ�ѡȡ�����Բ���i + 1
						sum -= candidates[i];
						path.pop_back();
				}
		}
public:
		// ��������
		void quicksort(vector<int>& arr, int start, int end)
		{
				if (start >= end) return;
				int left = start, right = end, pivot = arr[left];
				// �������󿴣�ֱ�������Ȼ�׼С�ģ����ӵ���׼���
				while (left < right && arr[right] >= pivot) right--;
				arr[left] = arr[right];
				// �������ҿ���֪�������Ȼ�׼��ģ����ӵ���׼�ұ�
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