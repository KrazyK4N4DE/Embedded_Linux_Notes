#ifndef __STRINGBAD_H__
#define __STRINGBAD_H__

#include <iostream>

using namespace std;

class StringBad
{
private:
        char *str;
        int len;
        static int num_strings;
public:
        StringBad(const char *s);
        StringBad();
        ~StringBad(); //析构函数，用到delete
        friend ostream &operator<<(ostream &os, const StringBad &st);

};

#endif