/*
进阶排序算法
*/
#include <iostream>
using namespace std;

// 快速排序
void QuickSort(int arr[], int start, int end)
{
		if (start >= end) return;
		int left = start, right = end, pivot = arr[left];  // pivot是比较的基准
		while (left < right)
		{
				while (left < right && arr[right] >= pivot) right--;  // 从右向左看，直到遇到比基准小的
				arr[left] = arr[right];  // 遇到比基准小的，就丢到左边去
				while (left < right && arr[left] <= pivot) left++;  // 从左向右看，直到遇到比基准大的
				arr[right] = arr[left];  // 遇到比基准大的，就丢到右边去
		}
		arr[left] = pivot;  // 再把基准值换回来
		// 基准值左右的数组分区快排 (不包含基准)
		QuickSort(arr, start, left - 1);
		QuickSort(arr, left + 1, end);
}

// 希尔排序
void ShellSort(int arr[], int size)
{
		int step = size / 2;  // 步长
		while (step >= 1)
		{
				for (int i = step; i < size; i++)  // 原先的插排是i = 1，现在是i = step
				{
						int tmp = arr[i], j = i;
						for (; j >= step && arr[j - step] > tmp; j -= step)
								arr[j] = arr[j - step];
						arr[j] = tmp;
				}
				step /= 2;  // 重新计算步长
		}
}

// 交换函数
void Swap(int* a, int* b)
{
		int tmp = *a;
		*a = *b;
		*b = tmp;
}
// 堆化函数
void MakeHeap(int arr[], int start, int end)
{
		while (start * 2 + 1 <= end)     //如果有子树，就一直往下，因为调整之后有可能子树又不满足性质了
		{
				int child = start * 2 + 1;    //因为下标是从0开始，且堆是从下标1开始放元素，所以左孩子下标就是i * 2 + 1，右孩子下标就是i * 2 + 2
				if (child + 1 <= end && arr[child] < arr[child + 1])   //如果存在右孩子且右孩子比左孩子大
						child++;    //那就直接看右孩子
				if (arr[child] > arr[start])   //如果上面选出来的孩子，比父结点大，那么就需要交换，大的换上去，小的换下来
						Swap(&arr[child], &arr[start]);
				start = child;   //继续按照同样的方式前往孩子结点进行调整
		}
}
// 堆排序
void HeapSort(int arr[], int size)
{
		for (int i = size / 2 - 1; i >= 0; i--)   //我们首选需要对所有非叶子结点进行一次堆化操作，需要从最后一个到第一个，这里size/2计算的位置刚好是最后一个非叶子结点
				MakeHeap(arr, i, size - 1);
		for (int i = size - 1; i > 0; i--)    //接着我们需要一个一个把堆顶元素搬到后面，有序排列
		{
				Swap(&arr[i], &arr[0]);    //搬运实际上就是直接跟倒数第i个元素交换，这样，每次都能从堆顶取一个最大的过来
				MakeHeap(arr, 0, i - 1);   //每次搬运完成后，因为堆底元素被换到堆顶了，所以需要再次对根结点重新进行堆化
		}
}

int main()
{
		int arr[] = { 3, 5, 7, 2, 9, 0, 6, 1, 8, 4 };
		//QuickSort(arr, 0, 9);
		//ShellSort(arr, 10);
		HeapSort(arr, 10);
		for (int i = 0; i < 10; i++)
				cout << arr[i] << " ";

		return 0;
}