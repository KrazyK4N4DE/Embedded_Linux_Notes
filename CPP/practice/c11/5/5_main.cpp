#include<iostream>
#include "5.h"

using namespace std;

int main()
{
        /*
        类的自动类型转换，即Stonewt incognito(275);
        这里的275会被自动转换为double型，然后找到Stonewt(double lbs)
        */
        Stonewt incognito = 275; 
        Stonewt wolfe(285.7);
        Stonewt taft(21, 8);

        incognito.Set_Type(Stonewt::POUNDS);
        cout << incognito;
        wolfe.Set_Type(Stonewt::FLOAT_POUNDS);
        cout << wolfe;
        taft.Set_Type(Stonewt::STONE);
        cout << taft;

        //验证运算符重载
        taft = incognito + wolfe;
        taft.Set_Type(Stonewt::STONE);
        cout << taft;

        taft = wolfe - incognito;
        taft.Set_Type(Stonewt::FLOAT_POUNDS);
        cout << taft;

        incognito = incognito * 2;
        incognito.Set_Type(Stonewt::POUNDS);
        cout << incognito;

        return 0;
}