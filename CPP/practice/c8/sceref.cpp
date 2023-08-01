#include <iostream>

using namespace std;

int main()
{
        int rats = 101;
        int &rodents = rats; // rodents is a reference
        cout << "rats = " << rats;
        cout << ", rodents = " << rodents << endl;
        
        int bunnies = 50;
        rodents = bunnies; //rats也变成了50
        cout << "bunnies = " << bunnies << endl;
        cout << "rodents = " << rodents << endl;
        cout << "rats = " << rats << endl;

        //address
        cout << "bunnies address = " << &bunnies << endl;
        cout << "rodents address = " << &rodents << endl;
        cout << "rats address = " << &rats << endl;

        return 0;
}