/*
�����
*/
#include <iostream>
using namespace std;

typedef int E;
typedef struct MaxHeap
{
		E* arr;
		int size;
		int capacity;
}* Heap;
// ��ʼ��
bool initHeap(Heap heap)
{
		heap->size = 0;
		heap->capacity = 10;
		heap->arr = new E[heap->capacity];
		return heap->arr != NULL;  // ���arr�������û���ͷ���True
}
// �������
bool insertHeap(Heap heap, E element)
{
		if (heap->size == heap->capacity) return 0;  // ���˾ͷ���False������������
		int index = ++(heap->size);  // index����Ϊ�����±꣬��Ϊ�±�0���Ŷ�����������������һ�㶼���ȷ�������������
		while (index > 1 && element > heap->arr[index / 2])  // ���±겻�Ǹ����λ�ã��Ҳ���Ԫ�ش��ڸ����ʱ�����жѻ�
		{
				// ���丸��㽻�� (����ʵ����ֻ�ǻ������ӽ���ֵ���ٰ��±�λ���Ƶ�����㴦)
				heap->arr[index] = heap->arr[index / 2];
				index /= 2;
		}
		heap->arr[index] = element;  // ����Ҫ�����λ��
		return 1;
}
// ɾ��
E deleteHeap(Heap heap)
{
		E max = heap->arr[1];  // Ҫɾ�Ŀ϶��Ƕ��ף��������
		E e = heap->arr[heap->size--];  // ��������Ԫ�ض���һ�£���Ϊɾ��һ����㣬����sizeҪ�Լ�һ��
		int index = 1;
		while (index * 2 <= heap->size)  // �������������û���ǾͲ�������
		{
				int child = index * 2;  // ���ӽ���λ��
				if (child < heap->size && heap->arr[child] < heap->arr[child + 1])  // ���ӽ���Ļ����ͻ�����
						child += 1;
				if (e >= heap->arr[child]) break;  // ����ӽ�㶼������Ļ����Ǿ������λ�ã�ֱ��break
				else heap->arr[index] = heap->arr[child];  // �ӽ���Ļ��Ͷѻ�
				index = child;  // ����index��λ�õ�����
		}
		heap->arr[index] = e;  // �ҵ����ʵ�λ����
		return max;
}
// ��ӡ
void printHeap(Heap heap)
{
		for (int i = 1; i <= heap->size; i++)
		{
				cout << heap->arr[i] << " ";
		}
}

int main()
{
		struct MaxHeap heap;
		initHeap(&heap);
		insertHeap(&heap, 5);
		insertHeap(&heap, 2);
		insertHeap(&heap, 3);
		insertHeap(&heap, 7);
		insertHeap(&heap, 6);

		for (int i = 0; i < 5; ++i) {
				printf("%d ", deleteHeap(&heap));
		}

		return 0;
}