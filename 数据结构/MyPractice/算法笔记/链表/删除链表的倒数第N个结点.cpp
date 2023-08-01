/*
* 删除链表的倒数第N个结点
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
                for (int i = 0; i <= n; i++) fast = fast->next;  // 快指针fast向后先走n+1步，为什么不是n？因为slow要指到倒数第n个结点的前一个，这样才好删除
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