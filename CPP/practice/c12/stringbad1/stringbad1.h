#ifndef __STRINGBAD1_H__
#define __STRINGBAD1_H__

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
        StringBad(const StringBad &st); //拷贝构造函数
        ~StringBad(); //析构函数，用到delete
        StringBad &operator=(const StringBad &st); //赋值运算符重载
        friend ostream &operator<<(ostream &os, const StringBad &st);

};

#endif