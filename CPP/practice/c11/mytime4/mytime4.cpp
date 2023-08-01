#include "mytime4.h"

Time::Time()
{
        hours = minutes = 0;
}

Time::Time(int h, int m)
{
        hours = h;
        minutes = m;
}

//加上m分钟，并且进行进位
void Time::AddMin(int m)
{
        minutes += m;
        hours += minutes / 60;
        minutes %= 60;
}

//加小时
void Time::AddHr(int h)
{
        hours += h;
}

//重置时间
void Time::Reset(int h, int m)
{
        hours = h;
        minutes = m;
}

//与另一个Time对象相加
Time Time::operator+(const Time &t) const
{
        Time sum;
        sum.minutes = minutes + t.minutes;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;

        return sum;
}

//与另一个Time对象相减
Time Time::operator-(const Time &t) const
{
        Time diff;
        int tot1, tot2;
        tot1 = hours * 60 + minutes;
        tot2 = t.hours * 60 + t.minutes;
        diff.hours = (tot1 - tot2) / 60;
        diff.minutes = (tot1 - tot2) % 60;

        return diff;
}

//乘一个系数，注意这里参数为double，所以使用时 * 右边必须是double，左边为调用对象
Time Time::operator*(double mult) const
{
        Time res;
        long tot = (hours * 60 + minutes) * mult;
        res.hours = tot / 60;
        res.minutes = tot % 60;

        return res;
}

ostream & operator<<(ostream &os, const Time &t)
{
        os << t.hours << "hours, " << t.minutes << "minutes\n";
        return os;
}

/*
void Time::Show() const
{
        cout << hours << " hours, " << minutes << " minutes.\n";
}
*/

//超屌的友元函数，可以直接访问Time对象的成员
Time operator*(double mult, const Time &t)
{
    Time res;
    long tot = (t.hours * 60 + t.minutes) * mult;
    res.hours = tot / 60;
    res.minutes = tot % 60;

    return res;
}