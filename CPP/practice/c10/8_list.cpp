#include<iostream>
#include "8_list.h"

using namespace std;

List::List()
{
        top = 0; 
}

bool List::isempty() const
{
        return top == 0;
}

bool List::isfull() const
{
        return top == MAX;
}

bool List::add(Item &item)
{
        if(top < MAX)
        {
                items[top++] = item;
                return true;
        }
        else
                return false;
}

void List::visit(void (*pf)(Item &item))
{
        for(int i = 0; i < top; i++)
                (*pf)(items[i]);
}
//访问列表中的每个元素
void visit_item(Item &item)
{
        cout << item << endl;
}