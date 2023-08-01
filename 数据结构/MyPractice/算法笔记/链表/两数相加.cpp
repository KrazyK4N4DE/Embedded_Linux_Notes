/*
* 两数相加
*/
#include <iostream>
using namespace std;
typedef long long ll;

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
        // 两个链表的同一位置可以相加，并考虑进位
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
                ListNode* dummyhead = new ListNode(0);
                ListNode* cur = dummyhead;
                bool flags = false;  // 进位位
                while (l1 != nullptr || l2 != nullptr)
                {
                        int num1 = (l1 ? l1->val : 0);
                        int num2 = (l2 ? l2->val : 0);  // l1或l2为空时，接下来的位就自动置0
                        int curNum = num1 + num2 + flags;
                        cur->next = new ListNode(curNum % 10);
                        flags = curNum / 10;

                        cur = cur->next;
                        if (l1 != nullptr) l1 = l1->next;
                        if (l2 != nullptr) l2 = l2->next;
                }
                if (flags > 0) cur->next = new ListNode(flags);  // 如果结束后还有进位
                return dummyhead->next;
        }
};

class SolutionWrong
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
        int pow(int n, int x)
        {
                ll res = 1;
                for (int i = 0; i < x; i++)
                {
                        res *= n;
                }
                return res;
        }
        ll linkToNum(ListNode* node)
        {
                ListNode* cur = node;
                ll total = 0;
                for (int i = 0; cur != nullptr; i++)
                {
                        total += (cur->val * pow(10, i));
                        cur = cur->next;
                }
                return total;
        }
        ListNode* numToLink(ll num)
        {
                ListNode* dummyhead = new ListNode(0);
                ListNode* curhead = dummyhead;
                while (num / 10 != 0)
                {
                        ll tmp = num % 10;
                        ListNode* tmpnode = new ListNode(tmp);
                        curhead->next = tmpnode;
                        curhead = curhead->next;
                        num /= 10;
                }
                ll tmp = num % 10;
                ListNode* tmpnode = new ListNode(tmp);
                curhead->next = tmpnode;
                return dummyhead->next;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
                ll n1 = linkToNum(l1);
                ll n2 = linkToNum(l2);
                ll total = n1 + n2;
                return numToLink(total);
        }
};

int main()
{
        return 0;
}