/*
使用友元函数重载所有运算符
*/
#include<iostream>
#include "4.h"

using namespace std;

int main()
{
        Time coding = Time(2, 40);
        Time fixing(5, 55);

        cout << "coding time = ";
        //coding.Show();
        cout << coding;
        cout << "fixing time = ";
        //fixing.Show();
        cout << fixing;

        Time total = coding + fixing;
        cout << "total time = ";
        //total.Show();
        cout << total;

        Time diff = fixing - coding;
        cout << "diff time = ";
        //diff.Show();
        cout << diff;

        Time mult1 = coding * 1.5; //没有友元函数时，不能写成 1.5 * coding
        cout << "mult1 time = ";
        //mult1.Show();
        cout << mult1;

        Time mult2 = 1.5 * coding; //调用非成员函数
        cout << "mult2 time = ";
        //mult2.Show();
        cout << mult2;

        cout << "*************************" << endl;
        cout << coding << fixing;

        return 0;
}