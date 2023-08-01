/*
* 有效的括号
*/
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
		stack<int> st;
		for (int i = 0; i < s.size(); i++)
		{
				// 检测到左括号时，将对应的右括号入栈
				if (s[i] == '(') st.push(')');
				else if (s[i] == '[') st.push(']');
				else if (s[i] == '{') st.push('}');
				// 如果栈为空或者不匹配时，返回false
				else if (st.empty() || st.top() != s[i]) return false;
				else st.pop();
		}
		return st.empty();
}

int main()
{
		return 0;
}