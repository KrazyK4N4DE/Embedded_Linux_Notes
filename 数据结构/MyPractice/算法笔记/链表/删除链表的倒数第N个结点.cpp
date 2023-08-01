/*
* ɾ������ĵ�����N�����
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
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
                ListNode* dummyhead = new ListNode(0, head);
                ListNode* fast = dummyhead;
                ListNode* slow = dummyhead;
                for (int i = 0; i <= n; i++) fast = fast->next;  // ��ָ��fast�������n+1����Ϊʲô����n����ΪslowҪָ��������n������ǰһ���������ź�ɾ��
                while (fast != NULL)
                {
                        fast = fast->next;
                        slow = slow->next;
                }
                ListNode* tmp = slow->next;
                slow->next = tmp->next;
                delete tmp;
                return dummyhead->next;
        }
};

int main()
{
        return 0;
}