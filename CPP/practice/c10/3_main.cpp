#include <iostream>
#include "3_golf.h"

using namespace std;

const int SIZE = 2;

int main()
{
        Golf g[SIZE] = 
        {
         Golf("Rick", 10)      
        };

        cout << "************************************" << endl;
        for(int count = 0; count < SIZE; count++)
        {
                g[count].Show();
        }

        return 0;
}