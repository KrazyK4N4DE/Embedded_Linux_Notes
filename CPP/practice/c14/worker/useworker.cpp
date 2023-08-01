#include <iostream>
#include "worker.h"

using namespace std;

const int LIM = 4;

int main()
{
        Waiter bob("Bob Apple", 314L, 5);
        Singer bev("Beverly Hills", 522L, 3);
        Waiter w_tmp;
        Singer s_tmp;

        Worker *pw[LIM] = {&bob, &bev, &w_tmp, &s_tmp};

        int i;
        for(i = 2; i < LIM; i++)
                pw[i] -> Set();

        for(i = 0; i < LIM; i++)
        {
                pw[i] -> Show();
                cout << endl;
        }

        return 0;
}