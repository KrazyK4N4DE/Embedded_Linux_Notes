#include <iostream>
#include "arraytp.h"

using namespace std;

int main()
{
        ArrayTP<int, 10> sums;
        ArrayTP<double, 10> aves;
        ArrayTP<ArrayTP<int, 5>, 10> twodee;

        int i, j;

        for(i = 0; i < 10; i++)
        {
                sums[i] = 0;
                for(j = 0; j < 5; j++)
                {
                        twodee[i][j] = (i + 1) * (j + 1);
                        sums[i] += twodee[i][j];
                }
                aves[i] = (double) sums[i] / 10;
        }

        for(i = 0; i < 10; i++)
        {
                for(j = 0; j < 5; j++)
                {
                        cout.width(2);
                        cout << twodee[i][j] << ' ';
                }
                cout << ": sum = " << sums[i] << "\tave = " << aves[i] << endl;
        }
        return 0;
}