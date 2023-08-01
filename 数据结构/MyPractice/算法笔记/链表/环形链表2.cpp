/*
* 环形链表Ⅱ(LeetCode142)
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
                ListNode* fast = head;  // fast走两步
                ListNode* slow = head;  // slow走一步
                while (fast != NULL && fast->next != NULL)
                {
                        fast = fast->next->next;
                        slow = slow->next;
                        // fast和slow肯定是在环内遇见，因为fast速度比slow快，在直线中绝对是遇不见的
                        // 在环内相当于是fast追着slow，fast相对于slow是以一步的速度追
                        if (fast == slow)
                        {
                                // 根据数学公式推导，链表头到环入口的距离与快慢指针相遇点接着走到环入口的距离相等
                                ListNode* index1 = head;  // 链表头
                                ListNode* index2 = fast;  // 快慢指针相遇点
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