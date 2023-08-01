/*
* �ö���ʵ��ջ
*/
#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
        // ��һ������ʵ��
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
                while (size--)  // ǰ���Ԫ�س��������
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