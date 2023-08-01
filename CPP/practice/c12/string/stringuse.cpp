/*
拷贝构造函数的重写以及赋值运算符的重载，防止按值传递出现问题
*/
#include <iostream>
#include "string.h"

const int MAX = 81;

int main()
{
        String name;

        cout << "Hi, what is your name?" << endl;
        cin >> name;

        cout << name << ", please enter a string: " << endl;
        String sayings1;
        char tmp[MAX];

        cin.get(tmp, MAX);
        while (cin && cin.get() != '\n')
                continue;
        sayings1 = tmp;

        cout << "Here is your sayings1: " << endl;
        cout << sayings1 << endl;

        String sayings2 = "Hello dad";
        if (sayings1.length() < sayings2.length())
                cout << "Sayings2 is longer.\n";
        else
                cout << "Sayings1 is longer.\n";

        if (sayings1 < sayings2)
                cout << "Sayings1's first letter is smaller.\n";
        else
                cout << "Sayings2's first letter is smaller.\n";

        cout << "This program used " << String::HowMany()
             << " String objects.\n";

        return 0;
}