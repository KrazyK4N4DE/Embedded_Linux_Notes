#include "6.h"

Move::Move(double a, double b)
{
        x = a;
        y = b;
}

void Move::showmove() const
{
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
}

Move Move::add(const Move &m) const
{
        Move tmp;

        tmp.x = x + m.x;
        tmp.y = y + m.y;

        return tmp;
}

void Move::reset(double a, double b)
{
        x = a;
        y = b;
}