#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

template <class Item>
class Queue
{
private:
        enum{Q_SIZE = 10};
        // struct Node {Item item; struct Node *next;};
        class Node
        {
        public:
                Item item;
                Node *next;
                Node(const Item &t) : item(t), next(NULL) {}
        };
        Node *front;
        Node *rear;
        int items;
        const int qsize;
public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item &item);
        bool dequeue(Item &item);
};

template <class Item>
Queue<Item>::Queue(int qs) : qsize(qs)
{
        front = rear = NULL;
        items = 0;
}

template <class Item>
bool Queue<Item>::isempty() const
{
        return items == 0;
}

template <class Item>
bool Queue<Item>::isfull() const
{
        return items == qsize;
}

template <class Item>
int Queue<Item>::queuecount() const
{
        return items;
}

template <class Item>
bool Queue<Item>::enqueue(const Item &item)
{
        if(isfull())
                return false;
        Node *add = new Node(item); //对类使用new，开辟内存空间，调用构造函数
        add -> item = item;
        add -> next = NULL;
        items++;

        if(front == NULL)
                front = add;
        else
                rear -> next = add;
        rear = add;

        return true;
}

template <class Item>
bool Queue<Item>::dequeue(Item &item)
{
        if(isempty())
                return false;
        item = front -> item;
        items--;

        Node *tmp = front;
        front = front -> next;
        delete tmp;

        if(items == 0)
                rear = NULL;

        return true;
}

//析构函数，队列解散后也要把所有的节点删除
template <class Item>
Queue<Item>::~Queue()
{
        Node *tmp;
        while(front != NULL)
        {
                tmp = front;
                front = front -> next;
                delete tmp;
        }
}

#endif