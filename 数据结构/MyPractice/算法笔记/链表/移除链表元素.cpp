/*
* �Ƴ�����Ԫ��
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
		// ��ʹ������ͷ���ķ���ɾ��Ԫ��
		ListNode* removeElements(ListNode* head, int val)
		{
				// ͷ�����Ҫɾ�������
				while (head != NULL && head->val == val)  // ���ǵ�ͷ���֮�����Ҳ���ܵ���val����Ҫɾ������ʹ��while
				{
						ListNode* tmp = head;
						head = head->next;
						delete tmp;
				}
				// ��ͷ�����Ҫɾ�������
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

		// ʹ������ͷ���ķ���ɾ��Ԫ��
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
				return vhead->next;  // head�����Ѿ���ɾ�ˣ����Բ�����
		}
};

int main()
{
		return 0;
}