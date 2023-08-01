/*
为什么运算符 =, ->, (), [] 只能在由类中的成员函数重载？
因为类里面提供了默认的这些运算符的重载功能，使用非成员函数会出现二义性。
如果成员函数重载，就会覆盖掉类里面的默认重载功能。
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
        void operator=(const int l);
};

Num::Num()
{
        n = 0;
        cout << "Hello world!" << endl;
}

Num::Num(int m)
{
        n = m;
        cout << "Good morning!" << endl;
}

//给默认的 = 运算符重载覆盖了
void Num::operator=(const int l)
{
        n = l;
        cout << "Good night!" << endl;
}


int main()
{
        Num a; //这一句调用Num()
        
        /*
        这样也行，
        因为在类中如果没对 = 重载，
        则main中出现 = 时，程序会自动调用 = 右侧值类型匹配的构造函数。
        即没重载调用Num(int m)，
        重载了调用operator=(const int l)。
        */
        a = 10;

        return 0;
}