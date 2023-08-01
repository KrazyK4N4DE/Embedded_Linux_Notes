#include<iostream>
#include "stonewt1.h"

using namespace std;

int main()
{
        /*
        强制类型转换
        */
        Stonewt poppins(9, 2.8);

        double p_wt = poppins; //强制类型转换：隐式
        cout << "poppins = " << p_wt << " pounds." << endl;

        int i_wt = poppins; //强制类型转换：隐式
        cout << "poppins = " << i_wt << " pounds." << endl;

        cout << "poppins = " << (int)poppins << " pounds." << endl; //强制类型转换：显式

        return 0;
}