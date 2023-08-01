#ifndef __EXC_MEAN_H__
#define __EXC_MEAN_H__

#include <iostream>

using namespace std;

// 调和平均数异常类
class bad_hmean
{
private:
        double v1;
        double v2;
public:
        bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        void mesg();
};

inline void bad_hmean::mesg()
{
        cout << "hmean(" << v1 << ", " << v2 << "): "
             << "invalid arguments: a = -b\n";
}

// 均值异常类
class bad_gmean
{
public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        const char* mesg();
};

inline const char *bad_gmean::mesg()
{
        return "gmean() arguments should be >= 0\n";
}

#endif