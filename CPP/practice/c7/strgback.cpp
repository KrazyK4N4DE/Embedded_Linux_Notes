#include <iostream>

using namespace std;

char *buildstr(char ch, int n);

int main()
{
        char ch;
        int n;
        cout << "Enter a character: ";
        cin >> ch;
        cout << "Enter an integer: ";
        cin >> n;
        char *ps = buildstr(ch, n);
        cout << ps << endl;
        delete[] ps;
        ps = buildstr('+', 20);
        cout << ps << "-DONE-" << ps << endl;
        delete[] ps;

        return 0;
}

char *buildstr(char ch, int n)
{
        char *pstr = new char[n + 1];
        for (int i = 0; i < n; i++)
                *(pstr + i) = ch;
        pstr[n] = '\0';
        return pstr;
}