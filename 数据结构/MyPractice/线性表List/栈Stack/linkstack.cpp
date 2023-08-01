/*
链栈
*/
#include <iostream>
using namespace std;

typedef int E;
struct LinkStack
{
		E data;
		struct LinkStack* next;
};
typedef LinkStack* Node;

/*初始化链栈*/
void initStack(Node head)
{
		head->next = NULL;
}


void showStack(Node head)
{
		while (head->next)
		{
				head = head->next;
				cout << head->data << " ";
		}
		cout << "|\n";
}

/*压栈操作*/
bool pushStack(Node head, E elem)
{
		Node node = new LinkStack;
		if (node == NULL) return 0;
		node->data = elem;
		node->next = head->next;
		head->next = node;
		return 1;
}

/*判断链栈是否为空*/
bool isEmpty(Node head)
{
		return head->next == NULL;
}

/*出栈操作*/
E popStack(Node head)
{
		Node tmp = head->next;
		head->next = head->next->next;
		E e = tmp->data;
		delete tmp;
		return e;
}

int main()
{
		LinkStack stack;
		initStack(&stack);

		for (int i = 1; i <= 10; ++i)
				pushStack(&stack, i * 100);
		showStack(&stack);

		while (!isEmpty(&stack))
				cout << popStack(&stack) << " ";
		cout << endl;

		return 0;
}