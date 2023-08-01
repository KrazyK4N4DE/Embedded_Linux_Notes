/*
单链表
*/
#include <iostream>

using namespace std;

/*定义结点*/
typedef int E;
struct ListNode
{
        E elem;
        struct ListNode* next;
};
typedef struct ListNode* Node;

/*初始化链表*/
void initList(Node node)
{
        node->next = NULL;
}

/*
打印展示链表元素
里面修改的是head的指向，并没有修改值
*/
void showList(Node head)
{
        while (head->next)
        {
                head = head->next;
                cout << head->elem << " ";
        }
        cout << endl;
}

/*在第index个位置的元素前插入elem*/
bool insertList(Node head, E elem, int index)
{
        if (index < 1)
                return 0;
        while (--index)  // 寻找第index个位置的前驱结点
        {
                head = head->next;
                if (head == NULL)
                        return 0;
        }

        // 插入元素
        Node node = new ListNode;
        if (node == NULL)
                return 0;
        node->elem = elem;
        node->next = head->next;
        head->next = node;

        return 1;
}

/*删除第index个位置的元素*/
bool deleteList(Node head, int index)
{
        if (index < 1)
                return 0;
        while (--index)  // 寻找第index个位置的前驱结点
        {
                head = head->next;
                if (head == NULL)
                        return 0;
        }

        // 删除元素
        Node tmp = head->next;
        head->next = tmp->next;
        delete tmp;

        return 1;
}

/*获取index对应位置的元素*/
E* getList(Node head, int index)
{
        if (index < 1)
                return 0;
        do
        {
                head = head->next;
                if (head == NULL)
                        return 0;
        } while (--index);

        return &head->elem;
}

/*通过元素查找对应的位置*/
int findList(Node head, E elem)
{
        head = head->next;  // 先走到第一个结点
        int i = 1;  // 计数器
        while (head)
        {
                if (head->elem == elem)  // 找到了就返回i
                        return i;
                head = head->next;
                i++;
        }

        return -1;  // 没有匹配的元素
}

/*获取链表长度*/
int sizeList(Node head)
{
        int i = -1;
        while (head)
        {
                head = head->next;
                ++i;
        }
        return i;
}

int main()
{
        ListNode list;
        initList(&list);
        
        for (int i = 1; i <= 3; ++i)
                insertList(&list, i * 100, i);
        showList(&list);

        deleteList(&list, 3);
        showList(&list);

        cout << "链表的长度：" << sizeList(&list) << endl;
        cout << "元素200在第" << findList(&list, 200) << "个位置\n";
        cout << "第1个元素为：" << *getList(&list, 1) << endl;

        return 0;
}