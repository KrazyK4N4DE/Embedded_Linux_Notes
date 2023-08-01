#include "string.h"
#include <cstring>

int String::num_strings = 0; //静态成员初始化要放在类外

int String::HowMany() //记得加作用域解析符
{
        return num_strings;
}

String::String(const char *s)
{
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        num_strings++;
}

String::String()
{
        len = 0;
        str = new char[1];
        str[0] = '\0';
        num_strings++;
}

String::String(const String &st)
{
        len = st.len;
        str = new char[len + 1];
        strcpy(str, st.str);
        num_strings++;
}

String::~String()
{
        --num_strings;
        delete[] str;
}

String &String::operator=(const String &st)
{
        //防止自己赋值给自己的时候，使用delete导致str没了
        if (this == &st)
                return *this;
        delete[] str;
        len = st.len;
        str = new char[len + 1];
        strcpy(str, st.str);
        return *this;
}

String &String::operator=(const char *s)
{
        delete[] str;
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        return *this;
}

char &String::operator[](int i)
{
        return str[i];
}

const char &String::operator[](int i) const
{
        return str[i];
}

bool operator<(const String &st1, const String &st2)
{
        // strcmp返回值为0表示相等，小于0表示st1小于st2，大于0表示st1大于st2
        return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
        //使用了重载的<运算符
        return (st2.str < st1.str);
}

bool operator==(const String &st1, const String &st2)
{
        // strcmp返回值为0表示相等，小于0表示st1小于st2，大于0表示st1大于st2
        return (strcmp(st1.str, st2.str) == 0);
}

istream &operator>>(istream &is, String &st)
{
        char tmp[String::CINLIMIT]; //别忘了加作用域解析符
        is.get(tmp, String::CINLIMIT);
        if (is)
                st = tmp; //使用了重载的赋值运算符
        while (is && is.get() != '\n')
                continue;
        return is;
}

ostream &operator<<(ostream &os, const String &st)
{
        os << st.str;
        return os;
}