#include<iostream>
#include "6.h"

int main()
{
        double x, y;
        Move m1(11.1, 22.2);
        m1.showmove();
        Move m2(10.0, 20.0);
        m2.showmove();
        Move m3;

        cout << "Enter x and y: ";
        cin >> x >> y;
        cout << "Reset m1: " << endl;
        m1.reset(x, y);
        m1.showmove();
        
        m3 = m1.add(m2);
        cout << "m3 = m1.add(m2): " << endl;
        m3.showmove();

        return 0;
}