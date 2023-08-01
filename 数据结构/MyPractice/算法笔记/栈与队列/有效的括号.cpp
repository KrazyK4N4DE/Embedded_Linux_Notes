/*
* ��Ч������
*/
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
		stack<int> st;
		for (int i = 0; i < s.size(); i++)
		{
				// ��⵽������ʱ������Ӧ����������ջ
				if (s[i] == '(') st.push(')');
				else if (s[i] == '[') st.push(']');
				else if (s[i] == '{') st.push('}');
				// ���ջΪ�ջ��߲�ƥ��ʱ������false
				else if (st.empty() || st.top() != s[i]) return false;
				else st.pop();
		}
		return st.empty();
}

int main()
{
		return 0;
}