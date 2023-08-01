#include<iostream>
#include "p2_stock10.h"

using namespace std;

int main()
{
/*
        //有默认构造函数时......
        Stock stock1;
        stock1.show();
*/
        //在没有默认构造函数时......
        Stock stock1 = Stock("Co name #1", 10, 12); //显式
        stock1.show();
        Stock stock2("Co name #2", 50, 2.5); //隐式
        stock2.show();

        cout <<"Assigning stock1 to stock2:" << endl;
        stock2 = stock1;
        cout << "Listing stock1 and stock2:" << endl;
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object:" << endl;
        stock1 = Stock("Nifty Foods", 10, 50.0); //不是初始化
        cout << "Revised stock1:" << endl;
        stock1.show();
        cout << "Done" << endl;

        return 0;
}