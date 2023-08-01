#include <iostream>

using namespace std;

void countdown(int n);

int main()
{
        countdown(4);

        return 0;
}

void countdown(int n)
{
        cout << "counting down... " << n 
        << endl << "(n at address: " << &n << ")\n";
        if (n > 0)
        {
                countdown(n-1);
        }
        cout << n << ": Kaboom!\n";
}