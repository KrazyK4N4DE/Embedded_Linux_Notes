//const int* pt;
//int* const pt;
//const int* const pt;

#include<iostream>

using namespace std;

int main()
{
    int n = 10;
    int* pt = &n;   //pt指向n
    cout << "1): n = " << n <<endl;
    *pt = 20;
    cout << "2): n = " << n <<endl;

    return 0;
}