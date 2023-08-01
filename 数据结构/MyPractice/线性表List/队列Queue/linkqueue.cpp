/*
链式队列
*/
#include <iostream>
using namespace std;

typedef int E;
struct LNode
{
		E data;
		struct LNode* next;
};
typedef LNode* Node;

struct Queue
{
		Node front;  // 头结点
		Node rear;  // 尾结点
};
typedef Queue* LinkQueue;

bool initQueue(LinkQueue queue)
{
		Node node = new LNode;
		if (node == NULL) return 0;
		queue->front = queue->rear = node;
		return 1;
}

void showQueue(LinkQueue queue)
{
		cout << "<<< ";
		Node node = queue->front->next;
		while (1)
		{
				cout << node->data << " ";
				if (node == queue->rear) break;
				else node = node->next;
		}
		cout << " <<<\n";
}

/*进队*/
bool enQueue(LinkQueue queue, E elem)
{
		Node node = new LNode;
		if (node == NULL) return 0;
		node->data = elem;
		queue->rear->next = node;  // 在尾结点后添加新结点
		queue->rear = node;  // 使node成为新的尾结点
		return 1;
}

bool isEmpty(LinkQueue queue)
{
		return queue->front == queue->rear;
}

/*出队*/
E deQueue(LinkQueue queue)
{
		Node tmp = queue->front->next;
		queue->front->next = queue->front->next->next;
		E e = tmp->data;
		// 如果刚好出队的是最后一个元素，队尾要在释放掉前移回队首位置上
		if (tmp == queue->rear) queue->rear = queue->front;
		delete tmp;
		return e;
}

int main()
{
		Queue queue;
		initQueue(&queue);

		for (int i = 1; i <= 10; ++i)
				enQueue(&queue, i * 100);
		showQueue(&queue);

		while (!isEmpty(&queue))
				cout << deQueue(&queue) << " ";
		cout << endl;

		return 0;
}