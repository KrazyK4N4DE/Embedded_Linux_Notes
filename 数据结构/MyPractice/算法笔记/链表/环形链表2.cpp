/*
* ���������(LeetCode142)
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
        ListNode* detectCycle(ListNode* head)
        {
                ListNode* fast = head;  // fast������
                ListNode* slow = head;  // slow��һ��
                while (fast != NULL && fast->next != NULL)
                {
                        fast = fast->next->next;
                        slow = slow->next;
                        // fast��slow�϶����ڻ�����������Ϊfast�ٶȱ�slow�죬��ֱ���о�������������
                        // �ڻ����൱����fast׷��slow��fast�����slow����һ�����ٶ�׷
                        if (fast == slow)
                        {
                                // ������ѧ��ʽ�Ƶ�������ͷ������ڵľ��������ָ������������ߵ�����ڵľ������
                                ListNode* index1 = head;  // ����ͷ
                                ListNode* index2 = fast;  // ����ָ��������
                                while (index1 != index2)
                                {
                                        index1 = index1->next;
                                        index2 = index2->next;
                                }
                                return index1;
                        }
                }
                return NULL;
        }
};

int main()
{
        return 0;
}