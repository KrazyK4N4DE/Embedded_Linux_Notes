#include <iostream>

using namespace std;

void swapr(int &a, int &b);
void swapp(int *a, int *b);
void swapv(int a, int b);

int main()
{
        int w1 = 300;
        int w2 = 350;

        //显示两个值
        cout << "w1 = " << w1 << endl;
        cout << "w2 = " << w2 << endl;

        cout << "Passing by value:\n";
        swapv(w1, w2);
        cout << "w1 = " << w1 << endl;
        cout << "w2 = " << w2 << endl;

        cout << "Passing by reference:\n";
        swapr(w1, w2);
        cout << "w1 = " << w1 << endl;
        cout << "w2 = " << w2 << endl;

        cout << "Passing by pointer:\n";
        swapp(&w1, &w2);
        cout << "w1 = " << w1 << endl;
        cout << "w2 = " << w2 << endl;

        return 0;
}

//按引用传递
void swapr(int &a, int &b)
{
        int tmp = a;
        a = b;
        b = tmp;
}

//按指针传递
void swapp(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

//按值传递
void swapv(int a, int b)
{
        int tmp = a;
        a = b;
        b = tmp;
}