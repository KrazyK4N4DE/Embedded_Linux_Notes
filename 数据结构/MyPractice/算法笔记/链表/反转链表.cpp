/*
* ��ת����
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
        // ˫ָ�뷨����˳��ÿ������ָ��ת
        ListNode* reverseList(ListNode* head)
        {
                ListNode* cur;  // ���ڴ洢��ǰѭ����Ӧ����Ľ��
                ListNode* pre = NULL;  // ����cur֮ǰ����ʼ��ΪNUL�����õ�һ����㷴תʱָ���
                while (head)
                {
                        cur = head;  // ָ��ǰ�����һ����㣬�൱���¸�ѭ��ʱ�����һλ
                        head = head->next;  // ��˳�����꣬������ÿ�����
                        cur->next = pre;  // ���ָ��ĵ�ת����
                        pre = cur;  // pre�����һλ����ѭ������ʱ���µ�ͷ���
                }
                return pre;
        }
        //�ݹ鷨
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