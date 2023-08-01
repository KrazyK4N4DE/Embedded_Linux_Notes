#include <iostream>

using namespace std;

double hmean(double, double);

int main()
{
        double x, y, z;

        cout << "Enter 2 numbers <q to quit>: ";
        while (cin >> x >> y)
        {
                try // 可能会引出异常的代码
                {
                        z = hmean(x, y);
                }
                catch (const char *s) // 处理异常
                {
                        cout << s << endl;
                        cout << "Enter a new pair of numbers: ";
                        continue;
                }

                cout << "Harmonic mean of " << x << " and " << y
                     << " is " << z << endl;
                cout << "Enter next set of numbers <q to quit>: ";
        }

        return 0;
}

double hmean(double a, double b)
{
        if (a == -b)
                throw "bad hmean() arguments: a = -b not allowed!!!"; // 抛出异常
        return 2.0 * a * b / (a + b);
}