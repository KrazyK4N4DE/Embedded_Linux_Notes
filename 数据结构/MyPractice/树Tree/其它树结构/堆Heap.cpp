/*
大根堆
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
// 初始化
bool initHeap(Heap heap)
{
		heap->size = 0;
		heap->capacity = 10;
		heap->arr = new E[heap->capacity];
		return heap->arr != NULL;  // 如果arr数组分配没错，就返回True
}
// 插入操作
bool insertHeap(Heap heap, E element)
{
		if (heap->size == heap->capacity) return 0;  // 满了就返回False，懒得扩容了
		int index = ++(heap->size);  // index定义为数组下标，因为下标0不放东西，所以先自增，一般都是先放在数组最后面的
		while (index > 1 && element > heap->arr[index / 2])  // 当下标不是根结点位置，且插入元素大于父结点时，进行堆化
		{
				// 与其父结点交换 (这里实际上只是换掉了子结点的值，再把下标位置移到父结点处)
				heap->arr[index] = heap->arr[index / 2];
				index /= 2;
		}
		heap->arr[index] = element;  // 最重要插入的位置
		return 1;
}
// 删除
E deleteHeap(Heap heap)
{
		E max = heap->arr[1];  // 要删的肯定是队首，即根结点
		E e = heap->arr[heap->size--];  // 用最后面的元素顶替一下，因为删了一个结点，所以size要自减一个
		int index = 1;
		while (index * 2 <= heap->size)  // 如果连左子树都没有那就不用找了
		{
				int child = index * 2;  // 左子结点的位置
				if (child < heap->size && heap->arr[child] < heap->arr[child + 1])  // 右子结点大的话，就换右子
						child += 1;
				if (e >= heap->arr[child]) break;  // 如果子结点都不够大的话，那就是这个位置，直接break
				else heap->arr[index] = heap->arr[child];  // 子结点大的话就堆化
				index = child;  // 更新index的位置到下面
		}
		heap->arr[index] = e;  // 找到合适的位置了
		return max;
}
// 打印
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