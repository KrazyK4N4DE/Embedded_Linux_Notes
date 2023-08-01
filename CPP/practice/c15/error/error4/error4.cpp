#include <iostream>
#include <cmath>
#include "exc_mean.h"

using namespace std;

double hmean(double, double);
double gmean(double a, double b);

int main()
{
        double x, y, z;

        cout << "Enter 2 numbers <q to quit>: ";
        while (cin >> x >> y)
        {
                try // 可能会引出异常的代码
                {
                        z = hmean(x, y);
                        cout << "Harmonic mean of " << x << " and " << y
                             << " is " << z << endl;
                        z = gmean(x, y);
                        cout << "Geometric mean of " << x << " and " << y
                             << " is " << z << endl;
                }
                catch (bad_hmean &bh) // 处理异常
                {
                        bh.mesg();
                        cout << "Enter a new pair of numbers: ";
                        continue;
                }
                catch (bad_gmean &bg)
                {
                        cout << bg.mesg();
                        cout << "Values used: " << bg.v1 << ", "
                             << bg.v2 << endl;
                        cout << "Sorry, you don't get to play any more.\n";
                        break;
                }

                cout << "Enter next set of numbers <q to quit>: ";
        }

        return 0;
}

double hmean(double a, double b)
{
        if (a == -b)
                throw bad_hmean(a, b); // 抛出异常，这里是一个对象
        return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
        if (a < 0 || b < 0)
                throw bad_gmean(a, b);
        return sqrt(a * b);
}