/*
���������㷨
*/
#include <iostream>
using namespace std;

// ��������
void QuickSort(int arr[], int start, int end)
{
		if (start >= end) return;
		int left = start, right = end, pivot = arr[left];  // pivot�ǱȽϵĻ�׼
		while (left < right)
		{
				while (left < right && arr[right] >= pivot) right--;  // �������󿴣�ֱ�������Ȼ�׼С��
				arr[left] = arr[right];  // �����Ȼ�׼С�ģ��Ͷ������ȥ
				while (left < right && arr[left] <= pivot) left++;  // �������ҿ���ֱ�������Ȼ�׼���
				arr[right] = arr[left];  // �����Ȼ�׼��ģ��Ͷ����ұ�ȥ
		}
		arr[left] = pivot;  // �ٰѻ�׼ֵ������
		// ��׼ֵ���ҵ������������ (��������׼)
		QuickSort(arr, start, left - 1);
		QuickSort(arr, left + 1, end);
}

// ϣ������
void ShellSort(int arr[], int size)
{
		int step = size / 2;  // ����
		while (step >= 1)
		{
				for (int i = step; i < size; i++)  // ԭ�ȵĲ�����i = 1��������i = step
				{
						int tmp = arr[i], j = i;
						for (; j >= step && arr[j - step] > tmp; j -= step)
								arr[j] = arr[j - step];
						arr[j] = tmp;
				}
				step /= 2;  // ���¼��㲽��
		}
}

// ��������
void Swap(int* a, int* b)
{
		int tmp = *a;
		*a = *b;
		*b = tmp;
}
// �ѻ�����
void MakeHeap(int arr[], int start, int end)
{
		while (start * 2 + 1 <= end)     //�������������һֱ���£���Ϊ����֮���п��������ֲ�����������
		{
				int child = start * 2 + 1;    //��Ϊ�±��Ǵ�0��ʼ���Ҷ��Ǵ��±�1��ʼ��Ԫ�أ����������±����i * 2 + 1���Һ����±����i * 2 + 2
				if (child + 1 <= end && arr[child] < arr[child + 1])   //��������Һ������Һ��ӱ����Ӵ�
						child++;    //�Ǿ�ֱ�ӿ��Һ���
				if (arr[child] > arr[start])   //�������ѡ�����ĺ��ӣ��ȸ�������ô����Ҫ��������Ļ���ȥ��С�Ļ�����
						Swap(&arr[child], &arr[start]);
				start = child;   //��������ͬ���ķ�ʽǰ�����ӽ����е���
		}
}
// ������
void HeapSort(int arr[], int size)
{
		for (int i = size / 2 - 1; i >= 0; i--)   //������ѡ��Ҫ�����з�Ҷ�ӽ�����һ�ζѻ���������Ҫ�����һ������һ��������size/2�����λ�øպ������һ����Ҷ�ӽ��
				MakeHeap(arr, i, size - 1);
		for (int i = size - 1; i > 0; i--)    //����������Ҫһ��һ���ѶѶ�Ԫ�ذᵽ���棬��������
		{
				Swap(&arr[i], &arr[0]);    //����ʵ���Ͼ���ֱ�Ӹ�������i��Ԫ�ؽ�����������ÿ�ζ��ܴӶѶ�ȡһ�����Ĺ���
				MakeHeap(arr, 0, i - 1);   //ÿ�ΰ�����ɺ���Ϊ�ѵ�Ԫ�ر������Ѷ��ˣ�������Ҫ�ٴζԸ�������½��жѻ�
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