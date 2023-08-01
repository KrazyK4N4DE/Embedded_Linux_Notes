/*
双链表
*/
#include <iostream>

using namespace std;

/*定义结点*/
typedef int E;
struct ListNode
{
		E elem;
		struct ListNode* prev;  // 前驱
		struct ListNode* next;  // 后驱
};
typedef struct ListNode* Node;

void initList(Node head)
{
		head->prev = NULL;
		head->next = NULL;
}

/*
打印展示链表元素
里面修改的是head的指向，并没有修改值
*/
void showList(Node head)
{
		while (head->next)
		{
				head = head->next;
				cout << head->elem << " ";
		}
		cout << endl;
}

/*
在第index个位置的元素前插入elem
双链表的操作比单链表要麻烦一些，但是思路都是差不多的
先让新结点指向index位置的结点，再让前驱结点指向自己
*/
bool insertList(Node head, E element, int index)
{
		if (index < 1) return 0;   //跟单链表一样，还是先找到对应的位置
		while (--index) {
				head = head->next;
				if (head == NULL) return 0;
		}
		Node node = new ListNode;  //创建新的结点
		if (node == NULL) return 0;
		node->elem = element;

		if (head->next) {   //首先处理后继结点，现在有两种情况，一种是后继结点不存在的情况，还有一种是后继结点存在的情况
				head->next->prev = node;   //如果存在则修改对应的两个指针
				node->next = head->next;
		}
		else {
				node->next = NULL;   //不存在直接将新结点的后继指针置为NULL
		}

		head->next = node;   //接着是前驱结点，直接操作就行
		node->prev = head;
		return 1;
}

/*删除第index个位置的元素*/
bool deleteList(Node head, int index)
{
		if (index < 1) return 0;
		while (--index)
		{
				head = head->next;
				if (head == NULL) return 0;
		}
		if (head->next == NULL) return 0;  // 都没有结点还删啥

		Node tmp = head->next;
		if (head->next->next)
		{
				head->next->next->prev = head;
				head->next = head->next->next;
		}
		else
				head->next = NULL;
		delete tmp;

		return 1;
}

int main()
{
		ListNode dlist;
		initList(&dlist);

		for (int i = 1; i <= 5; i++)
				insertList(&dlist, i * 100, i);

		Node tmp = &dlist;
		// 正向遍历一遍
		do
		{
				tmp = tmp->next;
				cout << tmp->elem << " -> ";
		} while (tmp->next);
		cout << endl;
		//再反向遍历
		do
		{
				cout << tmp->elem << " -> ";  // 刚才已经遍历到底了，所以把cout放在前面
				tmp = tmp->prev;
		} while (tmp->prev);
		cout << endl;

		deleteList(&dlist, 3);
		showList(&dlist);

		return 0;
}