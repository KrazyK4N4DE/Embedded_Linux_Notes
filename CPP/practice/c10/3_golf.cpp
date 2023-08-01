#include<iostream>
#include<cstring>
#include "3_golf.h"

using namespace std;

Golf::Golf(const char * name, int hc)
{
        strcpy(fullname, name);
        handicap = hc;
}

Golf::Golf()
{
        cout << "The fullname is: ";
        cin.getline(fullname, LEN);
        cout << "The handicap is: ";
        cin >> handicap;
        cin.get();
}

void Golf::Reset(int hc)
{
        handicap = hc;
}

void Golf::Show() const
{
        cout << "Name: " << fullname << endl;
        cout << "Handicap: " << handicap << endl;
}