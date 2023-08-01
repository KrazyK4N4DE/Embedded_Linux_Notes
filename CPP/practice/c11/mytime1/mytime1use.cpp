/*
运算符+的重载
*/
#include<iostream>
#include "mytime1.h"

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
        Time planning = coding.operator+(fixing);
        cout << "planning time = ";
        planning.Show();

        return 0;
}