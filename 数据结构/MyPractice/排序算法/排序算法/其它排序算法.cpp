/*
其它排序算法
*/
#include <iostream>
using namespace std;

// 数组合并
void Merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd)
{
		int i = left, size = rightEnd - left + 1;  // 这里需要保存一下当前范围长度，后面使用
		while (left <= leftEnd && right <= rightEnd)  // 如果两边都还有，那么就看哪边小，下一个就存哪一边的
		{
				if (arr[left] <= arr[right])
						tmp[i++] = arr[left++];
				else
						tmp[i++] = arr[right++];
		}
		while(left <= leftEnd)  // 如果右边看完了，只剩左边，直接把左边的存进去
				tmp[i++] = arr[left++];
		while (right <= rightEnd)  // 同上
				tmp[i++] = arr[right++];
		for (int j = 0; j < size; j++, rightEnd--)  // 全部存到暂存空间中之后，暂存空间中的内容都是有序的了，此时挨个搬回原数组中 (注意只能搬运范围内的)
				arr[rightEnd] = tmp[rightEnd];
}
// 归并排序
void MergeSort(int arr[], int tmp[], int start, int end)
{
		if (start >= end) return;
		int mid = (start + end) / 2;
		MergeSort(arr, tmp, start, mid);
		MergeSort(arr, tmp, mid + 1, end);
		Merge(arr, tmp, start, mid, mid + 1, end);
}

int main()
{
		int arr[] = { 3, 5, 7, 2, 9, 0, 6, 1, 8, 4 };
		int tmp[10];
		MergeSort(arr, tmp, 0, 9);
		for (int i = 0; i < 10; i++)
				cout << arr[i] << " ";

		return 0;
}