#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

using namespace std;

class Customer
{
private:
        long arrive;
        int processtime;
public:
        Customer() {arrive = processtime = 0;}
        void Set(long when);
        long when() const {return arrive;}
        int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue
{
private:
        enum{Q_SIZE = 10};
        struct Node {Item item; struct Node *next;};
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

#endif