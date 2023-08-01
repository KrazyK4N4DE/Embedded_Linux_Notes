/*
ƽ�������
*/
#include <iostream>
using namespace std;

typedef int E;
typedef struct BinaryTree
{
		E elem;
		struct BinaryTree* left, * right;
		int height;  // ��¼��ǰ�����߶ȣ��������ƽ������
}* bt;

bt createNode(E element)
{
		bt node = new BinaryTree;
		node->elem = element;
		node->left = node->right = NULL;
		node->height = 1;
		return node;
}
// ���������������߶�
int getMax(int a, int b)
{
		return a > b ? a : b;
}
// ��ȡ���ĸ߶�
int getHeight(bt root)
{
		if (root == NULL) return 0;
		return root->height;
}
// ����
bt leftRotate(bt root)
{
		bt newRoot = root->right;  //�м�ĵ��Ϊ�µĸ����
		root->right = newRoot->left;  //ԭ���м�ĵ���������ӵ��ɸ������ұ�
		newRoot->left = root;  // �µĸ��������Ǿɵĸ����
		// �����꣬Ҫ���¼�����������ĸ߶�
		root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
		newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
		return newRoot;
}
// ����
bt rightRotate(bt root)
{
		bt newRoot = root->left;
		root->left = newRoot->right;
		newRoot->right = root;
		// �����꣬Ҫ���¼�����������ĸ߶�
		root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
		newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
		return newRoot;
}
// ������������
bt leftRightRotate(bt root)
{
		root->left = leftRotate(root->left);
		return rightRotate(root);
}
// ������������
bt rightLeftRotate(bt root)
{
		root->right = rightRotate(root->right);
		return rightRotate(root);
}
// �������(������Ԫ�����)���������������������
bt insertNode(bt root, E element)
{
		if (root == NULL)
				root = createNode(element);
		else if (element < root->elem)
		{
				root->left = insertNode(root->left, element);
				// �����ж��Ƿ�ʧ��Ĵ���
				if (getHeight(root->left) - getHeight(root->right) > 1)
				{
						if (element < root->left->elem)  // Ԫ�ر����ӽ�㻹С����Ԫ�ؾͲ����ȥ�ˣ������LL��
								root = rightRotate(root);
						else  // LR��
								root = leftRightRotate(root);
				}
		}
		else if (element > root->elem)
		{
				root->right = insertNode(root->right, element);
				if (getHeight(root->left) - getHeight(root->right) < -1)
				{
						if (element > root->right->elem)  // RR��
								root = leftRotate(root);
						else  // RL��
								root = rightLeftRotate(root);
				}
		}
		root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;  // �����¸߶�
		return root;
}

int main()
{
		bt root = NULL;
		while (1)
		{
				E e;
				cin >> e;
				root = insertNode(root, e);
				cout << "";
		}

		return 0;
}