#include <iostream>
#include "1_golf.h"

using namespace std;

const int SIZE = 2;

int main()
{
        Golf g[SIZE];
        int count = 0;

        cout << "Please enter the name and handicap of the golfers: " << endl;
        while((count < SIZE) && setgolf(g[count]))
        {
                cout << "Please enter next golfer: " << endl;
                count++;
        }

        cout << "************************************" << endl;
        for(int i = 0; i < count; i++)
        {
                showgolf(g[i]);
        }

        return 0;
}