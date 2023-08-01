#include <iostream>

using namespace std;

int main()
{
        int rats = 101;
        int &rodents = rats; // rodents is a reference
        cout << "rats = " << rats;
        cout << ", rodents = " << rodents << endl;
        rodents++;
        cout << "rats = " << rats;
        cout << ", rodents = " << rodents << endl;

        //address
        cout << "rats address = " << &rats;
        cout << ", rodents address = " << &rodents << endl;

        return 0;
}