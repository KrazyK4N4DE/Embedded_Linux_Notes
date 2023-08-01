/*
非成员函数进行运算符重载
由于类里面的私有变量只能通过成员函数访问，所以把private改成public
但是不太安全
*/
#include<iostream>

using namespace std;

class Num
{
public:
        int n;
public:
        Num();
        Num(int m);
        void Show() const;
};

Num::Num()
{
        n = 0;
}

Num::Num(int m)
{
        n = m;
}

void Num::Show() const
{
        cout << n << endl;
}

Num operator+(const Num &j, const Num &k)
{
        return (j.n + k.n);
}

int main()
{
        Num a(10);
        a.Show();

        Num b(20);
        b.Show();

        Num c;
        c = a + b;
        c.Show();

        return 0;
}