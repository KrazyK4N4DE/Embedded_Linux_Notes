#include "2.h"
#include<cstring>

Person::Person(const string &ln, const char *fn)
{
        last = ln;
        strcpy(first, fn);
}

void Person::Show() const 
{
        if((last == "") && (first[0] == '\0'))
                cout << "No name!" << endl;
        else
                cout << first << " " << last << endl;
}

void Person::FormalShow() const
{
        if((last == "") && (first[0] == '\0'))
                cout << "No name!" << endl;
        else
                cout << last << ", " << first << endl;
}