/*
可变参数模板的使用。
输出结果中，最后的一个参数后面的逗号改成换行符。
该操作需要一个接受一个参数的同名函数模板。
*/
#include <iostream>
#include <string>

using namespace std;

void Show_list() {}

template<typename T>
void Show_list(const T &value)
{
      cout << value << endl;
}

template<typename T, typename... Args>
void Show_list(const T &value, const Args &... args)
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
        Show_list(x * x, '!', 7, mr);

        return 0;
}