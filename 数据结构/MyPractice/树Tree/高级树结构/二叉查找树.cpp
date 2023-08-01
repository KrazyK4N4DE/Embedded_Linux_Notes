/*
二叉查找树
*/
#include <iostream>
using namespace std;

typedef int E;
typedef struct BinaryTree
{
	E elem;
	struct BinaryTree* left, * right;
}* bt;

//创建
bt CreateTree(E elem)
{
		bt node = new BinaryTree;
		node->elem = elem;
		node->left = node->right = NULL;
		return node;
}
// 中序遍历
void inOrder(bt root)
{
		if (root == NULL) return;
		inOrder(root->left);
		cout << root->elem << " ";
		inOrder(root->right);
}
// 插入操作(不考虑元素相等)
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
// 查找指定值的结点，有就返回结点的地址，没有就返回NULL
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
// 找最大值，一路向右即可
bt findMax(bt root)
{
		while (root && root->right)
				root = root->right;
		return root;
}
// 删除操作
bt DeleteNode(bt root, E target)
{
		if (root == NULL) return NULL;  // 没找到要删除的点
		if (target < root->elem)
				root->left = DeleteNode(root->left, target);
		else if (target > root->elem)
				root->right = DeleteNode(root->right, target);
		else  // 找到了
		{
				if (root->left && root->right)  // 结点的度数为2
				{
						bt maxnode = findMax(root->left);  // 左子树中最大值
						root->elem = maxnode->elem;  // 替换值
						root->left = DeleteNode(root->left, root->elem);  // 替换好后，以同样方式删除替换上来的点
				}
				else  // 点的度数为1或0
				{
						bt tmp = root;
						if (root->left)  // 不是左就是右，将root指向为其中一个子结点，因为返回是返回给递归的上一级，相当于就自动连上了
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