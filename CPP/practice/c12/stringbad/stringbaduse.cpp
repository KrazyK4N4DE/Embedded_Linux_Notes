#include<iostream>
#include "stringbad.h"

void callme1(StringBad &rsb);
void callme2(StringBad sb);

int main()
{
        StringBad headline1 = "Hello world";
        StringBad headline2("Good morning");
        StringBad sports("I love you, Rick");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1); //传引用
        /*
        在这出了问题
        按值传递，说明是将实参赋值给了形参副本，
        等价于StringBad sb = headline2，又为StringBad sb = StringBad(headline2);
        构造函数中没有匹配的，故当一个对象初始化给另一个对象时，编译器会自动生成复制构造函数。
        复制构造函数不知道要更新num_strings，也不知道要开辟动态内存空间，
        但是对象创建了，结束后会调用析构函数。
        所以程序调用了4次构造函数，只有3次是new了空间，
        调用了4次析构函数，但是delete了4次空间。
        所以会出现错误。
        */
        callme2(headline2);

        return 0;
}

void callme1(StringBad &rsb)
{
        cout << "String passed by reference: " << rsb << endl;
}

void callme2(StringBad sb)
{
        cout << "String passed by value: " << sb << endl;
}