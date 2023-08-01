#include <iostream>
#include "stack.h"

using namespace std;

template <template <class T> class Thing>
class Crab
{
private:
        Thing<int> s1;
        Thing<double> s2;
public:
        bool push(int x, double y) {return s1.push(x) && s2.push(y);}
        bool pop(int &x, double &y) {return s1.pop(x) && s2.pop(y);}
};

int main()
{
        int ni;
        double nb;

        Crab<Stack> nebula;

        cout  << "\nEnter int & double pairs (0 0 to end): \n";
        // 输入并压入栈
        while((cin >> ni >> nb) && ((ni != 0) || (nb != 0)))
        {
                if(!nebula.push(ni, nb))
                        break;
        }

        // 从栈中弹出
        while(nebula.pop(ni, nb))
                cout << ni << ", " << nb << " : Out from stack." << endl;

        return 0;
}