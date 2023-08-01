#include <iostream>

using namespace std;

template <typename T>
T max5(T t[]);

int main()
{
        int a[5] = {1, 2, 3, 4, 5};
        double b[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

        cout << max5(a) << endl;
        cout << max5(b) << endl;

        return 0;
}

template <typename T>
T max5(T t[])
{
        T max = t[0];
        for (int i = 0; i < 5; i++)
        {
                if(t[i] > max)
                        max = t[i];
        }
        return max;
}