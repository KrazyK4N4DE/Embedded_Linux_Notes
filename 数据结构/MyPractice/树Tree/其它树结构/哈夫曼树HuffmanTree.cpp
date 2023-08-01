/*
��������
*/

#include <iostream>
#include <string>
using namespace std;

// ��������
typedef char E;
typedef struct HuffmanTree
{
		E elem;
		struct HuffmanTree* left, * right;
		int value;  // ���Ȩֵ
}*ht;
// �������
ht CreateNode(E element, int value)
{
		ht node = new HuffmanTree;
		node->elem = element;
		node->value = value;
		node->left = node->right = NULL;
		return node;
}

// ���ȼ�����
typedef ht NodeType;
typedef struct LinkNode  /*���еĽ��*/
{
		NodeType elem;
		struct LinkNode* next;
}* LNode;
typedef struct LinkQueue  /*����itself*/
{
		LNode front, rear;
}* LQueue;
// ��ʼ������
bool initQueue(LQueue queue)
{
		LNode node = new LinkNode;
		if (node == NULL) return 0;
		node->next = NULL;  // ��Ϊ�����õ����жϽ����һ��ΪNULL������Ĭ���趨ΪNULL
		queue->front = queue->rear = node;
		return 1;
}
//��ӣ���ȴ�ͳ���У����˸�VIP����ж�(ȨֵԽС��Խ����Խǰ��)
bool enQueue(LQueue queue, NodeType element)
{
		LNode node = new LinkNode;
		if (node == NULL) return 0;
		node->elem = element;
		node->next = NULL;  // ��Ϊ�����õ����жϽ����һ��ΪNULL������Ĭ���趨ΪNULL
		LNode pre = queue->front;  // ��ͷ��㿪ʼ��������Ƚ�
		while (pre->next && pre->next->elem->value <= element->value)  // ȨֵԽС��Խǰ��
				pre = pre->next;
		if (pre == queue->rear)  // ���˵�Ѿ���ͷ�ˣ���ôֱ�Ӳ���
		{
				queue->rear->next = node;
				queue->rear = node;
		}
		else  // ����Ͳ��
		{
				node->next = pre->next;
				pre->next = node;
		}
		return 1;
}
// ����
NodeType deQueue(LQueue queue)
{
		NodeType element = queue->front->next->elem;
		LNode tmp = queue->front->next;
		queue->front->next = queue->front->next->next;
		if (queue->rear == tmp) queue->rear = queue->front;
		delete(tmp);
		return element;
}
// ��ӡ����
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

// ���ַ������б���
string encode(ht root, E e) {
		if (root == NULL) return NULL;   //ΪNULL�϶�����û�ҵ�
		if (root->elem == e) return "";   //����ҵ��˾ͷ���һ���մ�
		string str = encode(root->left, e);  //��ȥ�����
		char* s = new char[10];
		if (!str.empty()) {
				s[0] = '0';
				str = s + str;   //�������ҵ��ˣ���ô�Ͱ���ߵ��Ѿ�ƴ�õ��ַ���ƴ�ӵ���ǰ�ĺ���
		}
		else {    //��߲������ٿ����ұ�
				str = encode(root->right, e);
				if (!str.empty()) {
						s[0] = '1';
						str = s + str;   //����ұ��ҵ��ˣ���ô�Ͱ��ұߵ��Ѿ�ƴ�õ��ַ���ƴ�ӵ���ǰ�ĺ���
				}
		}
		delete [] s;
		return str;   //��󷵻ز����õ��ַ�������һ��
}
// ��ӡ����������
void printEncode(ht root, E e)
{
		cout << e << "�ı���Ϊ��" << encode(root, e) << endl;
}

int main()
{
		struct LinkQueue queue;
		initQueue(&queue);
		enQueue(&queue, CreateNode('A', 5));
		enQueue(&queue, CreateNode('B', 16));
		enQueue(&queue, CreateNode('C', 8));
		enQueue(&queue, CreateNode('D', 13));

		// ������������
		while (queue.front->next != queue.rear)  // ������ڣ�˵��ɭ����ֻ��һ������
		{
				ht left = deQueue(&queue);
				ht right = deQueue(&queue);
				ht qnode = CreateNode(' ', left->value + right->value);
				qnode->left = left;
				qnode->right = right;
				enQueue(&queue, qnode);  // �������õ��������������
		}
		ht root = deQueue(&queue);  // �������ľ��ǹ���������

		printEncode(root, 'A');
		printEncode(root, 'B');
		printEncode(root, 'C');
		printEncode(root, 'D');

		return 0;
}