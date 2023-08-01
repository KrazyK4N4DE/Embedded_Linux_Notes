/*
使用友元函数重载 * 运算符
*/
#include<iostream>
#include "mytime3.h"

using namespace std;

int main()
{
        Time coding = Time(2, 40);
        Time fixing(5, 55);

        cout << "coding time = ";
        coding.Show();
        cout << "fixing time = ";
        fixing.Show();

        //运算符重载后的写法
        Time total = coding + fixing;
        cout << "total time = ";
        total.Show();
        //传统运算符重载的写法
        Time add = coding.operator+(fixing);
        cout << "add time = ";
        add.Show();

        Time diff = fixing - coding;
        cout << "diff time = ";
        diff.Show();

        Time mult1 = coding * 1.5; //没有友元函数时，不能写成 1.5 * coding
        cout << "mult1 time = ";
        mult1.Show();

        Time mult2 = 1.5 * coding; //调用非成员函数
        cout << "mult2 time = ";
        mult2.Show();

        return 0;
}