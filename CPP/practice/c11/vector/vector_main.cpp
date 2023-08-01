/*
* @brief  使用Vector类模拟醉鬼走路问题
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "vector.h"

using namespace std;
using namespace VECTOR;

int main()
{
        double target;
        double dstep;
        Vector drunk(0.0, 0.0);
        Vector step; //使用默认构造函数
        double direction;
        unsigned long steps = 0;

        srand(time(NULL));

        cout << "Enter target distance (q to quit): ";
        while(cin >> target)
        {
                cout << "Enter step length: ";
                if(!(cin >> dstep))
                        break;
                while(drunk.magval() < target)
                {
                        direction = rand() % 360;
                        step.reset(dstep, direction, Vector::POL);
                        steps++;
                        drunk = drunk + step;
                }
                cout << "After " << steps 
                << " steps, the subject has the following location:\n" 
                << drunk;
                drunk.polar_mode();
                cout << drunk << endl;

                drunk.reset(0.0, 0.0); //重置醉鬼的位置
                steps = 0; //重置步数

                cout << "Enter target distance (q to quit): ";
        }

        return 0;
}