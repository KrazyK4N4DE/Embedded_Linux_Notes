#include <iostream>

using namespace std;

long double sum_value() {cout << 0 << endl; return 0;}

template<typename T, typename...Vari>
long double sum_value(T value, Vari...a)
{
        long double sum = (long double)value + sum_value(a...);
        cout << sum << endl;
        return sum;
}

int main()
{
        cout << sum_value(1, 2, 3, 4, 5) << endl << endl;
        cout << sum_value('a', 'b', 2.2, 3.3, 5, 6, 7) << endl;

        return 0;
}