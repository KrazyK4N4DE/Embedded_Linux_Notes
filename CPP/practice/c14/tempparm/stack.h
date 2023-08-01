#ifndef __STACK_H__
#define __STACK_H__

template<class T>
class Stack
{
private:
        enum {MAX = 10}; //常量成员
        T items[MAX]; //存放栈中的元素
        int top; //栈顶

public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        //入栈，成功返回true，失败返回false
        bool push(const T &item);
        //出栈，成功返回true，失败返回false
        bool pop(T &item);

};

// 类模板的成员函数必须放到头文件中
template<class T>
Stack<T>::Stack()
{
        top = 0; //初始化栈顶，指向栈底，表示空栈
}

template<class T>
bool Stack<T>::isempty() const
{
        return top == 0;
}

template<class T>
bool Stack<T>::isfull() const
{
        return top == MAX;
}

template<class T>
bool Stack<T>::push(const T &item)
{
        if(top < MAX)
        {
                items[top++] = item;
                return true;
        }
        else
                return false;
}

template<class T>
bool Stack<T>::pop(T &item)
{
        if(top > 0)
        {
                item = items[--top];
                return true;
        }
        else
                return false;
}

#endif