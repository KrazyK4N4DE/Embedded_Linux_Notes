#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

double hmean(double, double);
double gmean(double a, double b);

class bad_hmean : public logic_error
{
public:
        bad_hmean(const string &what_arg = "hmean, invalid arguments\n") : logic_error(what_arg) {}
};

class bad_gmean : public logic_error
{
public:
        bad_gmean(const string &what_arg = "gmean, invalid arguments\n") : logic_error(what_arg) {}
};

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
                        cout << bh.what();
                        cout << "Enter a new pair of numbers: ";
                        continue;
                }
                catch (bad_gmean &bg)
                {
                        cout << bg.what();
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
                throw bad_hmean(); // 抛出异常，这里是一个对象
        return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
        if (a < 0 || b < 0)
                throw bad_gmean();
        return sqrt(a * b);
}