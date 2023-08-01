#include <iostream>
#include <new>

using namespace std;

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
        double *pd1, *pd2, *pd3, *pd4;
        int i;
        pd1 = new double[N];
        pd2 = new (buffer) double[N];
        cout << "pd1 address: " << pd1 << endl
             << "buffer address: " << (void *)buffer << endl
             << "******************************" << endl;
        for (i = 0; i < N; i++)
        {
                pd2[i] = pd1[i] = 1000 + 20.0 * i;
                cout << pd1[i] << " at " << &pd1[i] << "; ";
                cout << pd2[i] << " at " << &pd2[i] << endl;
        }
        cout << "******************************" << endl;
        
        pd3 = new double[N];
        pd4 = new (buffer) double[N];
        for(i = 0; i < N; i++)
        {
                pd3[i] = pd4[i] = 1000 + 40.0 * i;
                cout << pd3[i] << " at " << &pd3[i] << "; ";
                cout << pd4[i] << " at " << &pd4[i] << endl;
        }
        cout << "******************************" << endl;

        delete [] pd1;
        pd1 = new double[N];
        pd2 = new(buffer + N * sizeof(double)) double[N];
        for(i = 0; i < N; i++)
        {
                pd1[i] = pd2[i] = 1000 + 60.0 * i;
                cout << pd1[i] << " at " << &pd1[i] << "; ";
                cout << pd2[i] << " at " << &pd2[i] << endl;
        }

        /*
        pd2和pd4不能被delete，因为它们分配的内存是在buffer中的，而不是在堆中的
        */
        delete [] pd1;
        delete [] pd3;

        return 0;
}