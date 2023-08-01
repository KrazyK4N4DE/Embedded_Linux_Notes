/*
可变参数模板的使用。
输出结果中，最后的一个参数后面有逗号，不够美观。
*/
#include <iostream>
#include <string>

using namespace std;

void Show_list() {}

template<typename T, typename... Args>
void Show_list(T value, Args... args)
{
      cout << value << ", ";
      Show_list(args...);
}

int main()
{
        int n = 14;
        double x = 2.71828;
        string mr = "Mr. Rick";

        Show_list(n, x);
        cout << endl;
        Show_list(x * x, '!', 7, mr);
        cout << endl;

        return 0;
}