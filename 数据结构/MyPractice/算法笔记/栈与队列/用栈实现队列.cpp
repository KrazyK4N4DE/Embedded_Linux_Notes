/*
* 用栈实现队列
*/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
        stack<int> stackIn;
        stack<int> stackOut;
        MyQueue() { }

        void push(int x)
        {
                stackIn.push(x);
        }

        int pop()
        {
                if (stackOut.empty())
                        while (!stackIn.empty())  // 若stackOut为空，则把stackIn的全部元素导入进来
                        {
                                stackOut.push(stackIn.top());
                                stackIn.pop();
                        }
                int res = stackOut.top();
                stackOut.pop();
                return res;
        }

        int peek()
        {
                int res = this->pop();  // 复用，但是把元素弹出来了
                stackOut.push(res);
                return res;
        }

        bool empty()
        {
                return stackIn.empty() && stackOut.empty();
        }
};

int main()
{
		return 0;
}