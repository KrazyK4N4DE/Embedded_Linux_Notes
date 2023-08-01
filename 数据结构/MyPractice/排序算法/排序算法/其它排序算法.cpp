/*
���������㷨
*/
#include <iostream>
using namespace std;

// ����ϲ�
void Merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd)
{
		int i = left, size = rightEnd - left + 1;  // ������Ҫ����һ�µ�ǰ��Χ���ȣ�����ʹ��
		while (left <= leftEnd && right <= rightEnd)  // ������߶����У���ô�Ϳ��ı�С����һ���ʹ���һ�ߵ�
		{
				if (arr[left] <= arr[right])
						tmp[i++] = arr[left++];
				else
						tmp[i++] = arr[right++];
		}
		while(left <= leftEnd)  // ����ұ߿����ˣ�ֻʣ��ߣ�ֱ�Ӱ���ߵĴ��ȥ
				tmp[i++] = arr[left++];
		while (right <= rightEnd)  // ͬ��
				tmp[i++] = arr[right++];
		for (int j = 0; j < size; j++, rightEnd--)  // ȫ���浽�ݴ�ռ���֮���ݴ�ռ��е����ݶ���������ˣ���ʱ�������ԭ������ (ע��ֻ�ܰ��˷�Χ�ڵ�)
				arr[rightEnd] = tmp[rightEnd];
}
// �鲢����
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