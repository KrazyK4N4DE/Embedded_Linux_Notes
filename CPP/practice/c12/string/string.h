#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>

using namespace std;

class String
{
private:
        char *str;
        int len;
        static int num_strings;
        static const int CINLIMIT = 80; // static加const可以在类声明定义为常量
public:
        String(const char *s);
        String();
        String(const String &st); //拷贝构造函数
        ~String();                //析构函数，用到delete
        int length() const { return len; }
        String &operator=(const String &st); //赋值运算符重载
        String &operator=(const char *s);
        char &operator[](int i);             //重载下标运算符
        const char &operator[](int i) const; //重载下标运算符

        friend bool operator<(const String &st1, const String &st2);
        friend bool operator>(const String &st1, const String &st2);
        friend bool operator==(const String &st1, const String &st2);
        friend istream &operator>>(istream &is, String &st);
        friend ostream &operator<<(ostream &os, const String &st);

        static int HowMany();
};

#endif