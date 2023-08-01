/*
循环顺序队列
*/
#include <iostream>
using namespace std;
const int MAXSIZE = 10;

typedef int E;
struct Queue
{
		E* array;
		int capacity;
		int front, rear;  // 头和尾
};
typedef Queue* ArrayQueue;

bool initQueue(ArrayQueue queue)
{
		queue->capacity = MAXSIZE;
		queue->array = new E[queue->capacity];
		if (queue->array == NULL) return 0;
		queue->front = queue->rear = 0;
		return 1;
}

void showQueue(ArrayQueue queue)
{
		cout << "<<< ";
		int i = queue->front;
		while (i != queue->rear)
		{
				i = (i + 1) % queue->capacity;
				cout << queue->array[i] << " ";
		}
		cout << " <<<\n";
}

/*进队操作*/
bool enQueue(ArrayQueue queue, E elem)
{
		int pos = (queue->rear + 1) % queue->capacity;
		if (pos == queue->front) return 0;  // 先判断队列有没有满
		// 没满的话，就可以表尾后移、赋值了
		queue->rear = pos;
		queue->array[queue->rear] = elem;
		return 1;
}

bool isEmpty(ArrayQueue queue)
{
		return queue->rear == queue->front;
}

/*出队操作*/
E deQueue(ArrayQueue queue)
{
		queue->front = (queue->front + 1) % queue->capacity;
		return queue->array[queue->front];
}

int main()
{
		Queue queue;
		initQueue(&queue);

		for (int i = 0; i < 5; ++i)
				enQueue(&queue, i * 100);
		showQueue(&queue);

		while (!isEmpty(&queue))
				cout << deQueue(&queue) << " ";
		cout << endl;

		return 0;
}