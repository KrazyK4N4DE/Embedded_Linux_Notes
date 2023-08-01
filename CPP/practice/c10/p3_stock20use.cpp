#include<iostream>
#include "p3_stock20.h"

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

        cout << "Now show the top value stock: " << endl;
        stock1.topval(stock2).show();

        return 0;
}