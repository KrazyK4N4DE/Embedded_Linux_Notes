#include<iostream>
#include<cstring>
#include "1_golf.h"

using namespace std;

void setgolf(Golf & g, const char * name, int hc)
{
        strcpy(g.fullname, name);
        g.handicap = hc;
}

int setgolf(Golf &g)
{
        int tmp = 1; //作返回值，用于判断是否输入了名字，默认1为成功输入
        cout << "Enter the name: ";
        cin.getline(g.fullname, LEN);
        if (g.fullname[0] == '\0')
        {
                tmp = 0;
                return tmp;
        }
        cout << "Enter the handicap: ";
        cin >> g.handicap;
        cin.get();
        return tmp;
}

void hanicap(Golf &g, int hc)
{
        g.handicap = hc;
}

void showgolf(const Golf &g)
{
        cout << "Name: " << g.fullname << endl;
        cout << "Handicap: " << g.handicap << endl;
}