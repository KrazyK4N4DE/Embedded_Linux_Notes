#include "mytime0.h"

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
Time Time::Sum(const Time &t) const
{
        Time sum;
        sum.minutes = minutes + t.minutes;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
}

void Time::Show() const
{
        cout << hours << " hours, " << minutes << " minutes.\n";
}