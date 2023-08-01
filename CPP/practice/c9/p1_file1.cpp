/*
调用main函数的文件
直角坐标系和极坐标系换算
*/
#include <iostream>
#include "p1_coordin.h"

using namespace std;

int main()
{
        rect rplace;
        polar pplace;

        cout << "Enter the x and y values: ";
        while(cin >> rplace.x >> rplace.y)
        {
                pplace = rect_to_polar(rplace);
                show_polar(pplace);
                cout << "Next 2 numbers(q to quit): ";
        }
        cout << "DONE\n";

        return 0;
}
