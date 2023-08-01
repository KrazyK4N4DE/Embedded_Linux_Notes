#include<iostream>
#include "p3_stock20.h"

using namespace std;

const int SIZE = 4;

int main()
{
        Stock stocks[SIZE] = 
        {
                Stock("NanoSmart", 12, 20.0),
                Stock("Boffo Objects", 200, 2.0),
                Stock("Monolithic Obelisks", 130, 3.25),
                Stock("Fleep Enterprises", 60, 6.5)
        };

        cout << "Stock holdings:" << endl;

        for(int st = 0; st < SIZE; st++)
                stocks[st].show();

        const Stock *top = &stocks[0];
        for(int st = 1; st < SIZE; st++)
                top = &top->topval(stocks[st]); //右值中topval返回的是对象，左值是const Stock *类型

        cout << "Most valuable holding:" << endl;
        (*top).show();

        return 0;
}