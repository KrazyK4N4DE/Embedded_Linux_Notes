/*
���������㷨���Ż�
*/
#include <iostream>
using namespace std;

// ð������
void BubberSort(int* arr, int size)
{
		for (int i = 0; i < size - 1; i++)  // �Ż�1������ֻ��Ҫsize - 1�֣���Ϊ���һ��ֻ��һ��Ԫ��δ�����Ҳ�������
		{
				bool flag = 1;  // �Ż�2�����λ��������һ�������ж�û�����κν�����˵�������Ѿ����������
				for (int j = 0; j < (size - 1) - i; j++)
				{
						if (arr[j] > arr[j + 1])
						{
								flag = 0;  // ��������ʱ����flag��0
								int tmp = arr[j + 1];
								arr[j + 1] = arr[j];
								arr[j] = tmp;
						}
				}
				if (flag) break;  // û��Ϊ0˵��û������������������ģ�����ѭ������ʡһ��ʱ��
		}
}

// ��������
void InsertSort(int arr[], int size)
{
		for (int i = 1; i < size; i++)  // int i = 1�Ǽ����һ��Ԫ��û����������֮˵
		{
				int tmp = arr[i], j = i;
				for (; j > 0 && arr[j - 1] > tmp; j--)
						arr[j] = arr[j - 1];
				arr[j] = tmp;
		}
}
// �������������������±�λ�� + 1
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
// �����������Ĳ������� (���ȶ�)
void InsertSortBS(int arr[], int size)
{
		for (int i = 1; i < size; i++)  // int i = 1�Ǽ����һ��Ԫ��û����������֮˵
		{
				int tmp = arr[i];
				int j = BinarySearch(arr, 0, i - 1, tmp);
				for (int k = i; k > j; k--)
						arr[k] = arr[k - 1];
				arr[j] = tmp;
		}
}

// ѡ������
void SelectSort(int arr[], int size)
{
		for (int i = 0; i < size - 1; i++)
		{
				int min = i;  // ��¼һ�µ�ǰ��С��Ԫ�أ�Ĭ����ʣ��Ԫ���еĵ�һ��Ԫ��
				for (int j = i; j < size; j++)
						if (arr[j] < arr[min]) min = j;
				int tmp = arr[min];
				arr[min] = arr[i];
				arr[i] = tmp;
		}
}
// ��������
void Swap(int* a, int* b)
{
		int tmp = *a;
		*a = *b;
		*b = tmp;
}
// ˫���ѡ������ (�Ż�)
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