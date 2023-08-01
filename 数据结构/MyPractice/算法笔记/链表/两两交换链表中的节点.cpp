/*
* 两两交换链表中的节点(LeetCode24)
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
                ListNode* dummyhead = new ListNode(0, head);  // 添加虚拟头结点，保证原头结点和非头结点的操作一致
                ListNode* cur = dummyhead;
                while (cur->next != NULL && cur->next->next != NULL)  // 保证偶数结点和奇数结点都有终止条件
                {
                        ListNode* preNode = cur->next;  // 记住两两交换中第一个结点
                        ListNode* nextNode = cur->next->next;  // 记住两两交换中第二个结点
                        ListNode* next2Node = cur->next->next->next;  // 这两个结点之后的结点，因为交换后指向该结点的节点也会改变
                        cur->next = cur->next->next;  // 0 → 2
                        nextNode->next = preNode;  // 2 → 1
                        preNode->next = next2Node;  // 1 → 3
                        cur = cur->next->next;
                }
                return dummyhead->next;
        }
};

int main()
{
		return 0;
}