#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)
{
        front = rear = NULL;
        items = 0;
}

bool Queue::isempty() const
{
        return items == 0;
}

bool Queue::isfull() const
{
        return items == qsize;
}

int Queue::queuecount() const
{
        return items;
}

bool Queue::enqueue(const Item &item)
{
        if(isfull())
                return false;
        Node *add = new Node;
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

bool Queue::dequeue(Item &item)
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
Queue::~Queue()
{
        Node *tmp;
        while(front != NULL)
        {
                tmp = front;
                front = front -> next;
                delete tmp;
        }
}

void Customer::Set(long when)
{
        arrive = when;
        processtime = rand() % 3 + 1;
}