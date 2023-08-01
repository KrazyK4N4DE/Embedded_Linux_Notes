#ifndef __LIST_H__
#define __LIST_H__

typedef unsigned long Item; //方便移植修改，实现ADT

void visit_item(Item &item);

class List
{
private:
        enum {MAX = 10}; //常量成员
        Item items[MAX];
        int top; 

public:
        List();
        bool isempty() const;
        bool isfull() const;
        bool add(Item &item);
        void visit(void (*pf)(Item &item));

};

#endif