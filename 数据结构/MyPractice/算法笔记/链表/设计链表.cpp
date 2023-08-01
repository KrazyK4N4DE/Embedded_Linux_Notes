/*
* …Ëº∆¡¥±Ì(LeetCode707)
*/
#include <iostream>
using namespace std;

class MyLinkedList
{
public:
        struct ListNode
        {
                int val;
                ListNode* next;
                ListNode(int x) : val(x), next(nullptr) {}
        };

        MyLinkedList() {
                dummyhead = new ListNode(0);
                size = 0;
        }

        int get(int index) {
                if (index >= size || index < 0) return -1;
                ListNode* cur = dummyhead;
                for (int i = 0; i <= index; i++) cur = cur->next;
                return cur->val;
        }

        void addAtHead(int val) {
                ListNode* node = new ListNode(val);
                node->next = dummyhead->next;
                dummyhead->next = node;
                size++;
        }

        void addAtTail(int val) {
                ListNode* cur = dummyhead;
                while (cur->next != NULL) cur = cur->next;
                ListNode* node = new ListNode(val);
                cur->next = node;
                size++;
        }

        void addAtIndex(int index, int val) {
                if (index == size)
                {
                        addAtTail(val);
                        return;
                }
                else if (index > size) return;
                ListNode* cur = dummyhead;
                for (int i = 0; i < index; i++) cur = cur->next;
                ListNode* node = new ListNode(val);
                node->next = cur->next;
                cur->next = node;
                size++;
        }

        void deleteAtIndex(int index) {
                if (index >= size || index < 0) return;
                ListNode* cur = dummyhead;
                for (int i = 0; i < index; i++) cur = cur->next;
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                size--;
        }
private:
        int size;
        ListNode* dummyhead;
};

int main()
{
		return 0;
}