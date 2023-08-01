/*
������������
*/
#include <iostream>
using namespace std;

typedef char E;
typedef struct BinaryTree
{
		int leftTag, rightTag;  // ����1��ʾ��Ϊ�������������ӽ������
		struct BinaryTree* left, * right;
		struct BinaryTree* parent;  // ���������Ҫ
		E elem;
}* bt;

BinaryTree* CreateTree(E element)
{
		bt root = new BinaryTree;
		root->leftTag = root->rightTag = 0;
		root->left = root->right = NULL;
		root->elem = element;
		return root;
}

// ��ǰ�����Ϊ������������
bt pre = NULL;  // ��Ҫһ��ȫ�ֱ��������溯���е�ǰ����ǰһ�����
void preOrderThread(bt root)
{
		if (root == NULL) return;
		if (root->left == NULL)  // �жϵ�ǰ�������Ƿ�ΪNULL������ǣ���ָ����һ�����
		{
				root->left = pre;  // ָ����һ�����
				root->leftTag = 1;
		}
		if (pre && pre->right == NULL)  // �ж���һ�������ұ��Ƿ�ΪNULL�������������������һ�������ұ�ָ��ǰ���
		{
				pre->right = root;
				pre->rightTag = 1;
		}
		pre = root;  // ÿ������һ����Ҫ����pre����ʾ��һ�������Ľ��
		if (root->leftTag == 0)
				preOrderThread(root->left);
		if (root->rightTag == 0)
				preOrderThread(root->right);
}
// ǰ�������Ҫ��֮ǰ����������֮�����ʹ��
void preOrder(bt root)
{
		while (root)
		{
				cout << root->elem;
				if (root->leftTag == 0)
						root = root->left;
				else
						root = root->right;
		}
}

// ����������������Լ�֮��ı���
bt in = NULL;
void inOrderThread(bt root)
{
		if (root == NULL) return;
		if (root->leftTag == 0)
				inOrderThread(root->left);
		if (root->left == NULL)  // �жϵ�ǰ�������Ƿ�ΪNULL������ǣ���ָ����һ�����
		{
				root->left = in;  // ָ����һ�����
				root->leftTag = 1;
		}
		if (in && in->right == NULL)  // �ж���һ�������ұ��Ƿ�ΪNULL�������������������һ�������ұ�ָ��ǰ���
		{
				in->right = root;
				in->rightTag = 1;
		}
		in = root;  // ÿ������һ����Ҫ����in����ʾ��һ�������Ľ��
		if (root->rightTag == 0)
				inOrderThread(root->right);
}
void inOrder(bt root)
{
		while (root)
		{
				while (root && root->leftTag == 0)
						root = root->left;
				cout << root->elem;
				while (root && root->rightTag == 1)
				{
						root = root->right;
						cout << root->elem;
				}
				root = root->right;
		}
}

// ����������������Լ�֮��ı���
bt post = NULL;
void postOrderThread(bt root)
{
		if (root == NULL) return;
		if (root->leftTag == 0)
		{
				postOrderThread(root->left);
				if (root->left) root->left->parent = root;  // ������º������Ϊ�գ��Ǿ��趨���ӹ�ϵ
		}
		if (root->rightTag == 0)
		{
				postOrderThread(root->right);
				if (root->right) root->right->parent = root;  // �ұ����º������Ϊ�գ��Ǿ��趨���ӹ�ϵ
		}
		if (root->left == NULL)  // �жϵ�ǰ�������Ƿ�ΪNULL������ǣ���ָ����һ�����
		{
				root->left = post;  // ָ����һ�����
				root->leftTag = 1;
		}
		if (post && post->right == NULL)  // �ж���һ�������ұ��Ƿ�ΪNULL�������������������һ�������ұ�ָ��ǰ���
		{
				post->right = root;
				post->rightTag = 1;
		}
		post = root;  // ÿ������һ����Ҫ����post����ʾ��һ�������Ľ��
}
void postOrder(bt root)
{
		bt node = root, last = NULL;  // �����ݴ�ָ�룬lastΪ��һ�α����Ľ�㣬node��Ϊ����root�����ڸ���㣬��Ϊ�����������и������Ҫ���⴦��
		while (node)
		{
				while (node->left != last && node->leftTag == 0)  // һֱ���󣬲���ֹ����ѭ��
						node = node->left;
				while (node && node->rightTag == 1)  // ����굽�ұ�
				{
						cout << node->elem;
						last = node;
						node = node->right;
				}
				// ���⴦�������������ص������
				if (node == root && node->right == last)
				{
						cout << node->elem;
						return;
				}
				// �����������أ�����㲻�Ǹ����
				while (node && node->right == last)
				{
						cout << node->elem;
						last = node;
						node = node->parent;
				}
				// ���һ��������������������������ұ�Ҫô������Ҫô������������������
				if (node && node->rightTag == 0)  // ������ӽ�㣬�������ߣ�������������ǵ���һ����˵
						node = node->right;
		}
}

int main()
{
		bt a = CreateTree('A');
		bt b = CreateTree('B');
		bt c = CreateTree('C');
		bt d = CreateTree('D');
		bt e = CreateTree('E');

		a->left = b;
		a->right = c;
		b->left = d;
		b->right = e;

		//cout << "ǰ������Ľ��: ";
		//preOrderThread(a);
		//preOrder(a);
		//cout << "��������Ľ��: ";
		//inOrderThread(a);
		//inOrder(a);
		cout << "��������Ľ��: ";
		postOrderThread(a);
		postOrder(a);

		return 0;
}