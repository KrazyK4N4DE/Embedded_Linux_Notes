/*
* @brief  使用Vector类模拟醉鬼走路问题，并报告N次实验的最高、最低和平均步数
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "vector.h"

using namespace std;
using namespace VECTOR;

int main()
{
        unsigned int N;
        double target;
        double dstep;
        Vector drunk(0.0, 0.0);
        Vector step; //使用默认构造函数
        double direction;
        unsigned long steps = 0;
        unsigned long max =0;
        unsigned long min = 0;
        unsigned long sum = 0;

        srand(time(NULL));

        cout << "How many times do you want to run the experiment?: ";
        cin >> N;
        cout << "Enter target distance: ";
        cin >> target;
        cout << "Enter step length: ";
        cin >> dstep;
        for(int i = 0; i < N; i++)
        {
                while(drunk.magval() < target)
                {
                        direction = rand() % 360;
                        step.reset(dstep, direction, Vector::POL);
                        steps++;
                        drunk = drunk + step;
                }

                max = (max > steps) ? max : steps;
                if(min == 0)
                        min = max;
                min = (min < steps) ? min : steps;
                sum += steps;

                drunk.reset(0.0, 0.0); //重置醉鬼的位置
                steps = 0; //重置步数
        }

        cout << "The max steps is " << max << endl;
        cout << "The min steps is " << min << endl;
        cout << "The average steps is " << (double)sum / N << endl;

        return 0;
}