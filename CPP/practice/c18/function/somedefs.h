#ifndef __SOMEDEFS_H__
#define __SOMEDEFS_H__

#include <iostream>

using namespace std;

// 函数模板
template<typename T, typename U>
T use_f(T v, U f)
{
        static int count = 0;
        count++;
        cout << "use_f count = " << count
        << ", \t&count = " << &count << endl;

        return f(v);  // 将v传递给f
}

class Fp
{
private:
        double z_;
public:
        Fp(double z = 1.0) : z_(z) {}
        double operator()(double p) {return z_ * p;}
};

class Fq
{
private:
        double z_;
public:
        Fq(double z = 1.0) : z_(z) {}
        double operator()(double p) {return z_ + p;}
};

#endif