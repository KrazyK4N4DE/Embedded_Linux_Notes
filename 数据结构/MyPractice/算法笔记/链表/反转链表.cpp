/*
* 反转链表
*/
#include <iostream>
using namespace std;

class Solution {
public:
        struct ListNode
        {
                int val;
                ListNode* next;
                ListNode() : val(0), next(nullptr) {}
                ListNode(int x) : val(x), next(nullptr) {}
                ListNode(int x, ListNode* next) : val(x), next(next) {}
        };
        // 双指针法，按顺序将每个结点的指向倒转
        ListNode* reverseList(ListNode* head)
        {
                ListNode* cur;  // 用于存储当前循环的应处理的结点
                ListNode* pre = NULL;  // 处在cur之前，初始化为NUL，好让第一个结点反转时指向空
                while (head)
                {
                        cur = head;  // 指向当前处理的一个结点，相当于下个循环时向后走一位
                        head = head->next;  // 按顺序走完，处理完每个结点
                        cur->next = pre;  // 结点指向的倒转操作
                        pre = cur;  // pre向后走一位，到循环结束时是新的头结点
                }
                return pre;
        }
        //递归法
        ListNode* reverse(ListNode* cur, ListNode* pre)
        {
                if (cur == NULL) return pre;
                ListNode* tmp = cur->next;
                cur->next = pre;
                return reverse(tmp, cur);
        }
        ListNode* reverseList(ListNode* head)
        {
                return reverse(head, NULL);
        }
};

int main()
{
		return 0;
}