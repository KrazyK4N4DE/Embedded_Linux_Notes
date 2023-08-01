/*
* �������������еĽڵ�(LeetCode24)
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
        ListNode* swapPairs(ListNode* head)
        {
                ListNode* dummyhead = new ListNode(0, head);  // �������ͷ��㣬��֤ԭͷ���ͷ�ͷ���Ĳ���һ��
                ListNode* cur = dummyhead;
                while (cur->next != NULL && cur->next->next != NULL)  // ��֤ż������������㶼����ֹ����
                {
                        ListNode* preNode = cur->next;  // ��ס���������е�һ�����
                        ListNode* nextNode = cur->next->next;  // ��ס���������еڶ������
                        ListNode* next2Node = cur->next->next->next;  // ���������֮��Ľ�㣬��Ϊ������ָ��ý��Ľڵ�Ҳ��ı�
                        cur->next = cur->next->next;  // 0 �� 2
                        nextNode->next = preNode;  // 2 �� 1
                        preNode->next = next2Node;  // 1 �� 3
                        cur = cur->next->next;
                }
                return dummyhead->next;
        }
};

int main()
{
		return 0;
}