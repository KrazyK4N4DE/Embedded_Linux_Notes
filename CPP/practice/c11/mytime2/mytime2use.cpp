/*
运算符 +, -, * 的重载
重载后使用运算符时，其左侧操作对象为调用对象，右侧为参数对象
*/
#include<iostream>
#include "mytime2.h"

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