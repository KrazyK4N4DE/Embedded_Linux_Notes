/*
线索化二叉树
*/
#include <iostream>
using namespace std;

typedef char E;
typedef struct BinaryTree
{
		int leftTag, rightTag;  // 等于1表示作为线索，否则是子结点连线
		struct BinaryTree* left, * right;
		struct BinaryTree* parent;  // 后序遍历需要
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

// 以前序遍历为基础的线索化
bt pre = NULL;  // 需要一个全局变量来储存函数中当前结点的前一个结点
void preOrderThread(bt root)
{
		if (root == NULL) return;
		if (root->left == NULL)  // 判断当前结点左边是否为NULL，如果是，则指向上一个结点
		{
				root->left = pre;  // 指向上一个结点
				root->leftTag = 1;
		}
		if (pre && pre->right == NULL)  // 判断上一个结点的右边是否为NULL，是则进行线索化，上一个结点的右边指向当前结点
		{
				pre->right = root;
				pre->rightTag = 1;
		}
		pre = root;  // 每遍历完一个需要更新pre，表示上一个遍历的结点
		if (root->leftTag == 0)
				preOrderThread(root->left);
		if (root->rightTag == 0)
				preOrderThread(root->right);
}
// 前序遍历，要在之前遍历线索化之后才能使用
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

// 中序遍历的线索化以及之后的遍历
bt in = NULL;
void inOrderThread(bt root)
{
		if (root == NULL) return;
		if (root->leftTag == 0)
				inOrderThread(root->left);
		if (root->left == NULL)  // 判断当前结点左边是否为NULL，如果是，则指向上一个结点
		{
				root->left = in;  // 指向上一个结点
				root->leftTag = 1;
		}
		if (in && in->right == NULL)  // 判断上一个结点的右边是否为NULL，是则进行线索化，上一个结点的右边指向当前结点
		{
				in->right = root;
				in->rightTag = 1;
		}
		in = root;  // 每遍历完一个需要更新in，表示上一个遍历的结点
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

// 后序遍历的线索化以及之后的遍历
bt post = NULL;
void postOrderThread(bt root)
{
		if (root == NULL) return;
		if (root->leftTag == 0)
		{
				postOrderThread(root->left);
				if (root->left) root->left->parent = root;  // 左边完事后，如果不为空，那就设定父子关系
		}
		if (root->rightTag == 0)
		{
				postOrderThread(root->right);
				if (root->right) root->right->parent = root;  // 右边完事后，如果不为空，那就设定父子关系
		}
		if (root->left == NULL)  // 判断当前结点左边是否为NULL，如果是，则指向上一个结点
		{
				root->left = post;  // 指向上一个结点
				root->leftTag = 1;
		}
		if (post && post->right == NULL)  // 判断上一个结点的右边是否为NULL，是则进行线索化，上一个结点的右边指向当前结点
		{
				post->right = root;
				post->rightTag = 1;
		}
		post = root;  // 每遍历完一个需要更新post，表示上一个遍历的结点
}
void postOrder(bt root)
{
		bt node = root, last = NULL;  // 两个暂存指针，last为上一次遍历的结点，node是为了让root保留在根结点，因为这里后序遍历中根结点需要特殊处理
		while (node)
		{
				while (node->left != last && node->leftTag == 0)  // 一直向左，并防止无限循环
						node = node->left;
				while (node && node->rightTag == 1)  // 左边完到右边
				{
						cout << node->elem;
						last = node;
						node = node->right;
				}
				// 特殊处理：从右子树返回到根结点
				if (node == root && node->right == last)
				{
						cout << node->elem;
						return;
				}
				// 从右子树返回，但结点不是根结点
				while (node && node->right == last)
				{
						cout << node->elem;
						last = node;
						node = node->parent;
				}
				// 最后一种情况，当从左子树回来，则右边要么是线索要么是右子树，所以向右
				if (node && node->rightTag == 0)  // 如果是子结点，则向右走；如果是线索，那等下一轮再说
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

		//cout << "前序遍历的结果: ";
		//preOrderThread(a);
		//preOrder(a);
		//cout << "中序遍历的结果: ";
		//inOrderThread(a);
		//inOrder(a);
		cout << "后序遍历的结果: ";
		postOrderThread(a);
		postOrder(a);

		return 0;
}