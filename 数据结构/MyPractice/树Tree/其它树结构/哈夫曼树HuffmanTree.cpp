/*
哈夫曼树
*/

#include <iostream>
#include <string>
using namespace std;

// 哈夫曼树
typedef char E;
typedef struct HuffmanTree
{
		E elem;
		struct HuffmanTree* left, * right;
		int value;  // 存放权值
}*ht;
// 创建结点
ht CreateNode(E element, int value)
{
		ht node = new HuffmanTree;
		node->elem = element;
		node->value = value;
		node->left = node->right = NULL;
		return node;
}

// 优先级队列
typedef ht NodeType;
typedef struct LinkNode  /*队列的结点*/
{
		NodeType elem;
		struct LinkNode* next;
}* LNode;
typedef struct LinkQueue  /*队列itself*/
{
		LNode front, rear;
}* LQueue;
// 初始化队列
bool initQueue(LQueue queue)
{
		LNode node = new LinkNode;
		if (node == NULL) return 0;
		node->next = NULL;  // 因为下面用到了判断结点下一个为NULL，所以默认设定为NULL
		queue->front = queue->rear = node;
		return 1;
}
//入队，相比传统队列，多了个VIP插队判断(权值越小或越大排越前面)
bool enQueue(LQueue queue, NodeType element)
{
		LNode node = new LinkNode;
		if (node == NULL) return 0;
		node->elem = element;
		node->next = NULL;  // 因为下面用到了判断结点下一个为NULL，所以默认设定为NULL
		LNode pre = queue->front;  // 从头结点开始挨个往后比较
		while (pre->next && pre->next->elem->value <= element->value)  // 权值越小排越前面
				pre = pre->next;
		if (pre == queue->rear)  // 如果说已经到头了，那么直接插入
		{
				queue->rear->next = node;
				queue->rear = node;
		}
		else  // 否则就插队
		{
				node->next = pre->next;
				pre->next = node;
		}
		return 1;
}
// 出队
NodeType deQueue(LQueue queue)
{
		NodeType element = queue->front->next->elem;
		LNode tmp = queue->front->next;
		queue->front->next = queue->front->next->next;
		if (queue->rear == tmp) queue->rear = queue->front;
		delete(tmp);
		return element;
}
// 打印队列
void printQueue(LQueue queue)
{
		cout << "<<< ";
		LNode node = queue->front->next;
		while (node)
		{
				cout << node->elem->elem << " ";
				node = node->next;
		}
		cout << "<<<\n";
}

// 对字符串进行编码
string encode(ht root, E e) {
		if (root == NULL) return NULL;   //为NULL肯定就是没找到
		if (root->elem == e) return "";   //如果找到了就返回一个空串
		string str = encode(root->left, e);  //先去左边找
		char* s = new char[10];
		if (!str.empty()) {
				s[0] = '0';
				str = s + str;   //如果左边找到了，那么就把左边的已经拼好的字符串拼接到当前的后面
		}
		else {    //左边不行那再看看右边
				str = encode(root->right, e);
				if (!str.empty()) {
						s[0] = '1';
						str = s + str;   //如果右边找到了，那么就把右边的已经拼好的字符串拼接到当前的后面
				}
		}
		delete [] s;
		return str;   //最后返回操作好的字符串给上一级
}
// 打印哈夫曼编码
void printEncode(ht root, E e)
{
		cout << e << "的编码为：" << encode(root, e) << endl;
}

int main()
{
		struct LinkQueue queue;
		initQueue(&queue);
		enQueue(&queue, CreateNode('A', 5));
		enQueue(&queue, CreateNode('B', 16));
		enQueue(&queue, CreateNode('C', 8));
		enQueue(&queue, CreateNode('D', 13));

		// 构建哈夫曼树
		while (queue.front->next != queue.rear)  // 如果等于，说明森林里只有一棵树了
		{
				ht left = deQueue(&queue);
				ht right = deQueue(&queue);
				ht qnode = CreateNode(' ', left->value + right->value);
				qnode->left = left;
				qnode->right = right;
				enQueue(&queue, qnode);  // 将构建好的新树放入队列中
		}
		ht root = deQueue(&queue);  // 最后出来的就是哈夫曼树了

		printEncode(root, 'A');
		printEncode(root, 'B');
		printEncode(root, 'C');
		printEncode(root, 'D');

		return 0;
}