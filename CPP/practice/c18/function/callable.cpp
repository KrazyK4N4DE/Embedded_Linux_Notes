/*
利用函数指针、函数对象、lambda表达式传递给函数模板，结果是函数模板实例化了5次。
体现了函数模板的低效。
*/
#include "somedefs.h"
#include <iostream>

using namespace std;

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main()
{
        double y = 1.21;

        // 用函数指针
        cout << use_f(y, dub) << endl;
        cout << use_f(y, square) << endl;

        // 用函数对象
        cout << use_f(y, Fp(5.0)) << endl;
        cout << use_f(y, Fq(5.0)) << endl;

        // 用lambda表达式
        cout << use_f(y, [](double u){return u * u;}) << endl;
        cout << use_f(y, [](double u){return u + u / 2.0;}) << endl;

        return 0;
}