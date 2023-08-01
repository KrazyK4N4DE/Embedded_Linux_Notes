#include <iostream>

using namespace std;

double betsy(int n);
double pam(int n);
void estimate(int lines, double (*pf)(int));

int main()
{
        int code;
        cout << "How many lines of code do u need: ";
        cin >> code;
        cout << "Betsy's: ";
        estimate(code, betsy);
        cout << endl;
        cout << "Pam's: ";
        estimate(code, pam);
        cout << endl;

        return 0;
}

double betsy(int n)
{
        return 0.05 * n;
}

double pam(int n)
{
        return 0.03 * n + 0.0004 * n * n;
}

void estimate(int lines, double (*pf)(int))
{
        cout << lines << " lines code will take"
             << (*pf)(lines) << " hour(s)\n";
}
