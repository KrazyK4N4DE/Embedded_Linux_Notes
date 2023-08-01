/*
���������
*/
#include <iostream>
using namespace std;

typedef int E;
typedef struct BinaryTree
{
	E elem;
	struct BinaryTree* left, * right;
}* bt;

//����
bt CreateTree(E elem)
{
		bt node = new BinaryTree;
		node->elem = elem;
		node->left = node->right = NULL;
		return node;
}
// �������
void inOrder(bt root)
{
		if (root == NULL) return;
		inOrder(root->left);
		cout << root->elem << " ";
		inOrder(root->right);
}
// �������(������Ԫ�����)
bt insert(bt root, E data)
{
		if (root)
		{
				if (data < root->elem)
						root->left = insert(root->left, data);
				else if (data > root->elem)
						root->right = insert(root->right, data);
		}
		else
				root = CreateTree(data);
		return root;
}
// ����ָ��ֵ�Ľ�㣬�оͷ��ؽ��ĵ�ַ��û�оͷ���NULL
bt find(bt root, E target)
{
		while (root)
		{
				if (target < root->elem)
						root = root->left;
				else if (target > root->elem)
						root = root->right;
				else
						return root;
		}
		return NULL;
}
// �����ֵ��һ·���Ҽ���
bt findMax(bt root)
{
		while (root && root->right)
				root = root->right;
		return root;
}
// ɾ������
bt DeleteNode(bt root, E target)
{
		if (root == NULL) return NULL;  // û�ҵ�Ҫɾ���ĵ�
		if (target < root->elem)
				root->left = DeleteNode(root->left, target);
		else if (target > root->elem)
				root->right = DeleteNode(root->right, target);
		else  // �ҵ���
		{
				if (root->left && root->right)  // ���Ķ���Ϊ2
				{
						bt maxnode = findMax(root->left);  // �����������ֵ
						root->elem = maxnode->elem;  // �滻ֵ
						root->left = DeleteNode(root->left, root->elem);  // �滻�ú���ͬ����ʽɾ���滻�����ĵ�
				}
				else  // ��Ķ���Ϊ1��0
				{
						bt tmp = root;
						if (root->left)  // ����������ң���rootָ��Ϊ����һ���ӽ�㣬��Ϊ�����Ƿ��ظ��ݹ����һ�����൱�ھ��Զ�������
								root = root->left;
						else
								root = root->right;
						delete tmp;
				}
		}
		return root;
}

int main()
{
		bt root = insert(NULL, 18);
		insert(root, 10);
		insert(root, 7);
		insert(root, 15);
		insert(root, 22);
		insert(root, 9);
		insert(root, 8);
		inOrder(root);
		cout << endl << find(root, 17) << endl
				<< find(root, 22) << endl;
		cout << findMax(root) << endl;
		DeleteNode(root, 10);
		inOrder(root);

		return 0;
}