/*
直角坐标系和极坐标系换算，函数传递结构的地址
*/
#include <iostream>
#include <cmath>

using namespace std;

struct polar
{
        double distance;
        double angle;
};
struct rect
{
        double x;
        double y;
};

void rect_to_polar(const rect* o, polar* answer);
void show_polar(const polar* o);

int main()
{
        rect rplace;
        polar pplace;

        cout << "Enter the x and y values: ";
        while(cin >> rplace.x >> rplace.y)
        {
                rect_to_polar(&rplace, &pplace);
                show_polar(&pplace);
                cout << "Next 2 numbers(q to quit): ";
        }
        cout << "DONE\n";

        return 0;
}

void rect_to_polar(const rect* o, polar* answer)
{

        answer->distance = sqrt(o->x * o->x + o->y * o->y);
        answer->angle = atan2(o->y, o->x);

}

void show_polar(const polar* o)
{
        const double RAD_TO_DEG = 57.29577951;

        cout << "distance = " << o->distance
             << ", angle = " << o->angle * RAD_TO_DEG
             << " degrees\n";
}