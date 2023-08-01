/*
函数模板
*/
#include <iostream>

template <typename T>
void Swap(T &a, T &b);

using namespace std;

int main()
{
        int i = 10;
        int j = 20;
        cout << "i, j = " << i << ", " << j << endl;
        cout << "Using compiler-generated int swapper:\n";
        Swap(i, j);
        cout << "Now i, j = " << i << ", " << j << endl;

        double x = 24.5;
        double y = 81.7;
        cout << "x, y = " << x << ", " << y << endl;
        cout << "Using compiler-generated int swapper:\n";
        Swap(x, y);
        cout << "Now x, y = " << x << ", " << y << endl;

        return 0;
}

//使用函数模板的交换两数函数
template <typename T>
void Swap(T &a, T &b) //首字母要用大写，小写的可能其他地方有重载过
{
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
}