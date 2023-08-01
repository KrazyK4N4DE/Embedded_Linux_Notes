/*
包含与结构有关的函数的代码
*/
#include<iostream>
#include<cmath>
#include "p1_coordin.h"

using namespace std;

polar rect_to_polar(rect o)
{
        polar answer;

        answer.distance = sqrt(o.x * o.x + o.y * o.y);
        answer.angle = atan2(o.y, o.x);

        return answer;
}

void show_polar(polar o)
{
        const double RAD_TO_DEG = 57.29577951;

        cout << "distance = " << o.distance
             << ", angle = " << o.angle * RAD_TO_DEG
             << " degrees\n";
}