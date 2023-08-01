/*

*/
#include <iostream>
#include <cctype>
#include "8_list.h"

using namespace std;

int main()
{
        List list;
        Item num;

        for(int i = 0; i < 2; i++)
        {
                cout << "Enter a number: ";
                cin >> num;
                list.add(num);
        }
        list.visit(visit_item);

        return 0;
}