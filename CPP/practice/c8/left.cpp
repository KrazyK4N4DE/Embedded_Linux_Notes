#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 81;

char *left(const char *str, int n = 1);

int main()
{
        char sample[SIZE];

        cout << "Enter a string: ";
        cin.get(sample, SIZE);

        char *ps = left(sample, 4);
        cout << ps << endl;
        delete[] ps;

        ps = left(sample);
        cout << ps << endl;
        delete[] ps;

        return 0;
}

//取一个字符串的前n个
char *left(const char *str, int n)
{
        if (n < 0)
                n = 0;

        int m = 0;
        while (m < n && str[m])
                m++;

        char *p = new char[m + 1];

        int i;
        for (i = 0; i < m; i++)
                p[i] = str[i];

        p[i] = '\0';

        return p;
}