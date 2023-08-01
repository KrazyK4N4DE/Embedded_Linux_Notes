/*
* @brief  使用Vector类模拟醉鬼走路问题，并存入文件中
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
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

        ofstream fout;
        fout.open("vector.txt");

        srand(time(NULL));

        cout << "Enter target distance (q to quit): ";
        while(cin >> target)
        {
                cout << "Enter step length: ";
                if(!(cin >> dstep))
                        break;

                fout << "Target distance: " << target << "; Step size: " << dstep << endl;
                while(drunk.magval() < target)
                {
                        direction = rand() % 360;
                        step.reset(dstep, direction, Vector::POL);
                        fout << steps << ": " << drunk; 
                        steps++;
                        drunk = drunk + step;
                }
                cout << "After " << steps 
                << " steps, the subject has the following location:\n" 
                << drunk;

                fout << "After " << steps
                << " steps, the subject has the following location:\n" 
                << drunk << "or\n";
                
                drunk.polar_mode();
                fout << drunk << "Average outward distance per step = " << drunk.magval() / steps << endl;
                cout << drunk << endl;

                drunk.reset(0.0, 0.0); //重置醉鬼的位置
                steps = 0; //重置步数

                cout << "Enter target distance (q to quit): ";
        }

        return 0;
}