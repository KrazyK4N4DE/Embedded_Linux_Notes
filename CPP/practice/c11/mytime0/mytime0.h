#ifndef __MYTIME0_H__
#define __MYTIME0_H__

#include<iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time Sum(const Time &t) const;
        /*
        这里返回类型不能用引用：Time &Sum(const Time &t) const;
        参数引用是为了提高效率，不用拷贝一份类。
        但是返回引用的话，因为返回局部变量sum对象的引用，
        函数执行完后，sum就被释放了，引用将指向一个不存在的对象。
        */
        void Show() const;
};

#endif