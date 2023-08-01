#ifndef __2_H__
#define __2_H__

#include<iostream>

using namespace std;

class Person
{
private:
        static const int LIMIT = 25;
        string last;
        char first[LIMIT];
public:
        //默认构造函数
        Person() {last = ""; first[0] = '\0';}
        //构造函数
        Person(const string &ln, const char *fn = "HeyYou");
        //显示名字(firstname在前)
        void Show() const;
        //显示名字(lastname在前)
        void FormalShow() const;
};

#endif