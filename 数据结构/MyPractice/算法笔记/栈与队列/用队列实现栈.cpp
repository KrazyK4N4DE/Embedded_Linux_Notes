/*
* 用队列实现栈
*/
#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
        // 用一个队列实现
        queue<int> que;
        MyStack()
        {

        }

        void push(int x)
        {
                que.push(x);
        }

        int pop()
        {
                int size = que.size() - 1;
                while (size--)  // 前面的元素出队再入队
                {
                        que.push(que.front());
                        que.pop();
                }
                int res = que.front();
                que.pop();
                return res;
        }

        int top()
        {
                return que.back();
        }

        bool empty()
        {
                return que.empty();
        }
};

int main()
{
		return 0;
}