/*
* ��ջʵ�ֶ���
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
                        while (!stackIn.empty())  // ��stackOutΪ�գ����stackIn��ȫ��Ԫ�ص������
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
                int res = this->pop();  // ���ã����ǰ�Ԫ�ص�������
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