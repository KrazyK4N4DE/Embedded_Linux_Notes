/*
栈通用操作
*/
#include "5_stack.h"

Stack::Stack()
{
        top = 0; //初始化栈顶，指向栈底，表示空栈
}

bool Stack::isempty() const
{
        return top == 0;
}

bool Stack::isfull() const
{
        return top == MAX;
}

bool Stack::push(const Item &item)
{
        if(top < MAX)
        {
                items[top++] = item;
                return true;
        }
        else
                return false;
}

bool Stack::pop(Item &item)
{
        if(top > 0)
        {
                item = items[--top];
                return true;
        }
        else
                return false;
}