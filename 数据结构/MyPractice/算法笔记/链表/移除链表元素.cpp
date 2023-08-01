/*
* 移除链表元素
*/
#include <iostream>
using namespace std;

class Solution
{
public:
		struct ListNode
		{
				int val;
				ListNode* next;
				ListNode() : val(0), next(nullptr) {}
				ListNode(int x) : val(x), next(nullptr) {}
				ListNode(int x, ListNode* next) : val(x), next(next) {}
		};
		// 不使用虚拟头结点的方法删除元素
		ListNode* removeElements(ListNode* head, int val)
		{
				// 头结点需要删除的情况
				while (head != NULL && head->val == val)  // 考虑到头结点之后的数也可能等于val，需要删掉，则使用while
				{
						ListNode* tmp = head;
						head = head->next;
						delete tmp;
				}
				// 非头结点需要删除的情况
				ListNode* cur = head;
				while (cur != NULL && cur->next != NULL)
				{
						if (cur->next->val == val)
						{
								ListNode* tmp = cur->next;
								cur->next = tmp->next;
								delete tmp;
						}
						else cur = cur->next;
				}
				return head;
		}

		// 使用虚拟头结点的方法删除元素
		ListNode* removeElements_virtual(ListNode* head, int val)
		{
				ListNode* vhead = new ListNode;
				vhead->next = head;
				ListNode* cur = vhead;
				while (cur != NULL && cur->next != NULL)
				{
						if (cur->next->val == val)
						{
								ListNode* tmp = cur->next;
								cur->next = tmp->next;
								delete tmp;
						}
						else cur = cur->next;
				}
				return vhead->next;  // head可能已经被删了，所以不能用
		}
};

int main()
{
		return 0;
}