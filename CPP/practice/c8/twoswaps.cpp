/*
函数模板显式具体化
*/
#include <iostream>

const int LIMIT = 20;

using namespace std;

struct job
{
        char name[LIMIT];
        float salary;
        int floor;
};

template <typename T>
void Swap(T &a, T &b);
template <>
void Swap<job>(job &j1, job &j2);
void show(job &j);

int main()
{
        int i = 10;
        int j = 20;
        cout << "i, j = " << i << ", " << j << endl;
        cout << "Using compiler-generated int swapper:\n";
        Swap(i, j);
        cout << "Now i, j = " << i << ", " << j << endl;

        job Rick = {"Rick", 1000.0, 10};
        job Jack = {"Jack", 2000.0, 20};
        show(Rick);
        show(Jack);
        Swap(Rick, Jack);
        cout << "After swapping:\n";
        show(Rick);
        show(Jack);

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

//显式具体化(优先级比常规模板高)：结构体
template <>
void Swap<job>(job &j1, job &j2)
{
        float tmp1;
        int tmp2;

        tmp1 = j1.salary;
        j1.salary = j2.salary;
        j2.salary = tmp1;

        tmp2 = j1.floor;
        j1.floor = j2.floor;
        j2.floor = tmp2;
}

void show(job &j)
{
        cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}