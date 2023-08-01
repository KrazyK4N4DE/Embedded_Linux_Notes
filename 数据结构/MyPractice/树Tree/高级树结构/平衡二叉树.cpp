/*
平衡二叉树
*/
#include <iostream>
using namespace std;

typedef int E;
typedef struct BinaryTree
{
		E elem;
		struct BinaryTree* left, * right;
		int height;  // 记录当前子树高度，方便计算平衡因子
}* bt;

bt createNode(E element)
{
		bt node = new BinaryTree;
		node->elem = element;
		node->left = node->right = NULL;
		node->height = 1;
		return node;
}
// 找左右子树的最大高度
int getMax(int a, int b)
{
		return a > b ? a : b;
}
// 获取结点的高度
int getHeight(bt root)
{
		if (root == NULL) return 0;
		return root->height;
}
// 左旋
bt leftRotate(bt root)
{
		bt newRoot = root->right;  //中间的点成为新的根结点
		root->right = newRoot->left;  //原来中间的点的左子树扔到旧根结点的右边
		newRoot->left = root;  // 新的根结点左边是旧的根结点
		// 左旋完，要重新计算上两个点的高度
		root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
		newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
		return newRoot;
}
// 右旋
bt rightRotate(bt root)
{
		bt newRoot = root->left;
		root->left = newRoot->right;
		newRoot->right = root;
		// 右旋完，要重新计算上两个点的高度
		root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
		newRoot->height = getMax(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
		return newRoot;
}
// 先左旋再右旋
bt leftRightRotate(bt root)
{
		root->left = leftRotate(root->left);
		return rightRotate(root);
}
// 先右旋再左旋
bt rightLeftRotate(bt root)
{
		root->right = rightRotate(root->right);
		return rightRotate(root);
}
// 插入操作(不考虑元素相等)，里面包含了左右旋操作
bt insertNode(bt root, E element)
{
		if (root == NULL)
				root = createNode(element);
		else if (element < root->elem)
		{
				root->left = insertNode(root->left, element);
				// 多了判断是否失衡的代码
				if (getHeight(root->left) - getHeight(root->right) > 1)
				{
						if (element < root->left->elem)  // 元素比左子结点还小，那元素就插左边去了，因此是LL型
								root = rightRotate(root);
						else  // LR型
								root = leftRightRotate(root);
				}
		}
		else if (element > root->elem)
		{
				root->right = insertNode(root->right, element);
				if (getHeight(root->left) - getHeight(root->right) < -1)
				{
						if (element > root->right->elem)  // RR型
								root = leftRotate(root);
						else  // RL型
								root = rightLeftRotate(root);
				}
		}
		root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;  // 计算下高度
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