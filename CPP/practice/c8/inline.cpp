#include <iostream>

using namespace std;

inline double sq(double x) { return x * x; }

int main()
{
        double a, b;
        double c = 13.0;

        a = sq(5.0);
        b = sq(4.5 + 7.5);
        cout << "a = " << a << ", b = " << b << endl;
        cout << "c = " << c;
        cout << ", c squared = " << sq(c++) << endl;

        return 0;
}