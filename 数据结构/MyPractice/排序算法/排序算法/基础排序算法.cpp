/*
基础排序算法及优化
*/
#include <iostream>
using namespace std;

// 冒泡排序
void BubberSort(int* arr, int size)
{
		for (int i = 0; i < size - 1; i++)  // 优化1：排序只需要size - 1轮，因为最后一轮只有一个元素未排序，且不用排了
		{
				bool flag = 1;  // 优化2：标记位，当在这一轮排序中都没出现任何交换，说明数组已经是有序的了
				for (int j = 0; j < (size - 1) - i; j++)
				{
						if (arr[j] > arr[j + 1])
						{
								flag = 0;  // 发生交换时，将flag置0
								int tmp = arr[j + 1];
								arr[j + 1] = arr[j];
								arr[j] = tmp;
						}
				}
				if (flag) break;  // 没变为0说明没交换，数组已是有序的，结束循环，节省一点时间
		}
}

// 插入排序
void InsertSort(int arr[], int size)
{
		for (int i = 1; i < size; i++)  // int i = 1是假设第一个元素没有有序无序之说
		{
				int tmp = arr[i], j = i;
				for (; j > 0 && arr[j - 1] > tmp; j--)
						arr[j] = arr[j - 1];
				arr[j] = tmp;
		}
}
// 二分搜索，返回数组下标位置 + 1
int BinarySearch(int arr[], int left, int right, int target)
{
		int mid;
		while (left <= right)
		{
				mid = (left + right) / 2;
				if (target == arr[mid]) return mid + 1;
				else if (target < arr[mid])
						right = mid - 1;
				else
						left = mid + 1;
		}
		return left;
}
// 带二分搜索的插入排序 (不稳定)
void InsertSortBS(int arr[], int size)
{
		for (int i = 1; i < size; i++)  // int i = 1是假设第一个元素没有有序无序之说
		{
				int tmp = arr[i];
				int j = BinarySearch(arr, 0, i - 1, tmp);
				for (int k = i; k > j; k--)
						arr[k] = arr[k - 1];
				arr[j] = tmp;
		}
}

// 选择排序
void SelectSort(int arr[], int size)
{
		for (int i = 0; i < size - 1; i++)
		{
				int min = i;  // 记录一下当前最小的元素，默认是剩余元素中的第一个元素
				for (int j = i; j < size; j++)
						if (arr[j] < arr[min]) min = j;
				int tmp = arr[min];
				arr[min] = arr[i];
				arr[i] = tmp;
		}
}
// 交换函数
void Swap(int* a, int* b)
{
		int tmp = *a;
		*a = *b;
		*b = tmp;
}
// 双向的选择排序 (优化)
void SelectSortPlus(int arr[], int size)
{
		int left = 0, right = size - 1;
		while (left < right)
		{
				int min = left, max = right;
				for (int i = left; i <= right; i++)
				{
						if (arr[i] < arr[min]) min = i;
						if (arr[i] > arr[max]) max = i;
				}

				Swap(&arr[max], &arr[right]);
				if (min == right) min = max;
				Swap(&arr[min], &arr[left]);

				left++;
				right--;
		}
}

int main()
{
		int arr[] = { 3, 5, 7, 2, 9, 0, 6, 1, 8, 4 };
		//BubberSort(arr, 10);
		//InsertSort(arr, 10);
		//InsertSortBS(arr, 10);
		//SelectSort(arr, 10);
		SelectSortPlus(arr, 10);
		for (int i = 0; i < 10; i++)
				cout << arr[i] << " ";

		return 0;
}