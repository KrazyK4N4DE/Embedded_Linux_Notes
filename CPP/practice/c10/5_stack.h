#ifndef __STACK_H__
#define __STACK_H__

typedef struct customer
{
        char fullname[35];
        double payment;
} Item; //方便移植修改，实现ADT

class Stack
{
private:
        enum {MAX = 10}; //常量成员
        Item items[MAX]; //存放栈中的元素
        int top; //栈顶

public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        //入栈，成功返回true，失败返回false
        bool push(const Item &item);
        //出栈，成功返回true，失败返回false
        bool pop(Item &item);

};

#endif