/*
使用包装器，能使得函数模板在接受同一特征标的函数指针、函数对象、lambda表达式后，只实例化一次。
*/
#include "somedefs.h"
#include <iostream>
#include <functional>

using namespace std;

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main()
{
        double y = 1.21;

        // 包装器
        function<double(double)> ef1 = dub;
        function<double(double)> ef2 = square;
        function<double(double)> ef3 = Fp(5.0);
        function<double(double)> ef4 = Fq(5.0);
        function<double(double)> ef5 = [](double u){return u * u;};
        function<double(double)> ef6 = [](double u){return u + u / 2.0;};

        // 用函数指针
        cout << use_f(y, ef1) << endl;
        cout << use_f(y, ef2) << endl;

        // 用函数对象
        cout << use_f(y, ef3) << endl;
        cout << use_f(y, ef4) << endl;

        // 用lambda表达式
        cout << use_f(y, ef5) << endl;
        cout << use_f(y, ef6) << endl;

        return 0;
}