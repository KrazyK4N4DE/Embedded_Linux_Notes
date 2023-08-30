#include <iostream>
using namespace std;

// �����
typedef char E;
typedef struct BinaryTree
{
		E elem;
		struct BinaryTree* left;
		struct BinaryTree* right;
		int flag;
}* bt;

//��ջ
struct LinkStack
{
		bt elem;
		struct LinkStack* next;
};
typedef struct LinkStack* SNode;
void initStack(SNode head)
{
		head->next = NULL;
}
bool pushStack(SNode head, bt elem)
{
		SNode node = new LinkStack;
		if (node == NULL) return 0;
		node->elem = elem;
		node->next = head->next;
		head->next = node;
		return 1;
}
bool isEmpty(SNode head)
{
		return (head->next == NULL);
}
// ���ڻ�ȡջ��Ԫ�ص�ֵ�������ǳ�ջ��������ֵ��ȡ
bt peekStack(SNode head)
{
		return head->next->elem;
}
bt popStack(SNode head)
{
		SNode tmp = head->next;
		head->next = head->next->next;
		bt e = tmp->elem;
		delete tmp;
		return e;
}

// ������
struct QueueNode
{
		bt elem;
		struct QueueNode* next;
};
typedef struct QueueNode* QNode;
struct LinkQueue
{
		struct QueueNode* front, * rear;
};
typedef struct LinkQueue* LQueue;
bool initQueue(LQueue queue)
{
		QNode node = new QueueNode;
		if (node == NULL) return 0;
		queue->front = queue->rear = node;
		return 1;
}
bool enQueue(LQueue queue, bt elem)
{
		QNode node = new QueueNode;
		if (node == NULL) return 0;
		node->elem = elem;
		queue->rear->next = node;
		queue->rear = node;
		return 1;
}
bool isEmpty(LQueue queue)
{
		return queue->front == queue->rear;
}
bt deQueue(LQueue queue)
{
		QNode tmp = queue->front->next;
		queue->front->next = queue->front->next->next;
		bt e = tmp->elem;
		if (queue->rear == tmp) queue->rear = queue->front;
		delete tmp;
		return e;
}

// ǰ�����(�ݹ�д��)������Ĳ���Ϊ�������ĸ����
void preOrder1(bt root)
{
		if (root == NULL) return;
		cout << root->elem;
		preOrder1(root->left);
		preOrder1(root->right);
}
// ǰ�����������Ĳ���Ϊ�������ĸ����
void preOrder2(bt root)
{
		struct LinkStack stack;
		initStack(&stack);
		while (root || !isEmpty(&stack))
		{
				while (root)
				{
						cout << root->elem;
						pushStack(&stack, root);
						root = root->left;
				}
				bt tmp = popStack(&stack);
				root = tmp->right;
		}
}
// �������(�ݹ�д��)������Ĳ���Ϊ�������ĸ����
void inOrder1(bt root)
{
		if (root == NULL) return;
		inOrder1(root->left);
		cout << root->elem;
		inOrder1(root->right);
}
// �������������Ĳ���Ϊ�������ĸ����
void inOrder2(bt root)
{
		struct LinkStack stack;
		initStack(&stack);
		while (root || !isEmpty(&stack))
		{
				while (root)
				{
						pushStack(&stack, root);
						root = root->left;
				}
				bt tmp = popStack(&stack);
				cout << tmp->elem;
				root = tmp->right;
		}
}
// �������(�ݹ�д��)������Ĳ���Ϊ�������ĸ����
void postOrder1(bt root)
{
		if (root == NULL) return;
		postOrder1(root->left);
		postOrder1(root->right);
		cout << root->elem;
}
// �������������Ĳ���Ϊ�������ĸ����
void postOrder2(bt root)
{
		LinkStack stack;
		initStack(&stack);
		while (root || !isEmpty(&stack))
		{
				while (root)
				{
						pushStack(&stack, root);
						root->flag = 0;
						root = root->left;
				}
				root = peekStack(&stack);
				if (root->flag == 0)
				{
						root->flag = 1;
						root = root->right;
				}
				else  // flag == 1����ʾ������������������
				{
						cout << root->elem;
						popStack(&stack);
						root = NULL;
				}
		}
}
// �������������Ĳ���Ϊ�������ĸ����
void levelOrder(bt root)
{
		struct LinkQueue queue;
		initQueue(&queue);
		enQueue(&queue, root);  // �ȰѸ�����װ����
		while (!isEmpty(&queue))
		{
				bt node = deQueue(&queue);
				cout << node->elem;
				if (node->left)
						enQueue(&queue, node->left);
				if (node->right)
						enQueue(&queue, node->right);
		}
}

int main()
{
		// ���������
		bt a = new BinaryTree;
		bt b = new BinaryTree;
		bt c = new BinaryTree;
		bt d = new BinaryTree;
		bt e = new BinaryTree;
		bt f = new BinaryTree;
		a->elem = 'A';
		b->elem = 'B';
		c->elem = 'C';
		d->elem = 'D';
		e->elem = 'E';
		f->elem = 'F';

		// ����
		a->left = b;
		a->right = c;
		b->left = d;
		b->right = e;
		c->right = f;
		c->left = NULL;
		f->left = f->right = NULL;
		d->left = d->right = NULL;
		e->left = e->right = NULL;

		cout << "ǰ������Ľ��(�ݹ�): ";
		preOrder1(a);
		cout << "\nǰ������Ľ��: ";
		preOrder2(a);
		cout << endl;

		cout << "\n��������Ľ��(�ݹ�): ";
		inOrder1(a);
		cout << "\n��������Ľ��: ";
		inOrder2(a);
		cout << endl;

		cout << "\n��������Ľ��(�ݹ�): ";
		postOrder1(a);
		cout << "\n��������Ľ��: ";
		postOrder2(a);
		cout << endl;

		cout << "\n��������Ľ��: ";
		levelOrder(a);
		cout << endl;

		return 0;
}