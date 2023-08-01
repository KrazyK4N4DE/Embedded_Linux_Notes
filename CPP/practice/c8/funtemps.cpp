/*
重载的函数模板
*/
#include <iostream>

const int LIMIT = 8;

template <typename T>
void Swap(T &a, T &b);
template <typename T>
void Swap(T a[], T b[], int n);
void show(int arr[]);

using namespace std;

int main()
{
        int i = 10;
        int j = 20;
        cout << "i, j = " << i << ", " << j << endl;
        cout << "Using compiler-generated int swapper:\n";
        Swap(i, j);
        cout << "Now i, j = " << i << ", " << j << endl;

        int d1[LIMIT] = {1, 2, 3, 4, 5, 6, 7, 8};
        int d2[LIMIT] = {0, 0, 9, 3, 0, 2, 0, 1};
        cout << "Original arrays:\n";
        show(d1);
        show(d2);
        Swap(d1, d2, LIMIT);
        cout << "Current arrays:\n";
        show(d1);
        show(d2);

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

//重载
template <typename T>
void Swap(T a[], T b[], int n)
{
        T tmp;
        for (int i = 0; i < n; i++)
        {
                tmp = a[i];
                a[i] = b[i];
                b[i] = tmp;
        }
}

void show(int arr[])
{
        for (int i = 0; i < LIMIT; i++)
                cout << arr[i] << " ";
        cout << endl;
}