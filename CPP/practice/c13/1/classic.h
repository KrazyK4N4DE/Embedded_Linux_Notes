#ifndef __CLASSIC_H__
#define __CLASSIC_H__

#include <iostream>

using namespace std;

// 唱片类
class Cd
{
private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
public:
        Cd(char *per, char *l, int n, double t);
        Cd(const Cd &d);
        Cd();
        virtual ~Cd() {}
        virtual void Report() const;
        Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
        char mainwork[50];
public:
        Classic(char *per, char *l, char *mw, int n, double t);
        Classic();
        Classic(const Classic &c);
        virtual ~Classic() {}
        virtual void Report() const;
        Classic &operator=(const Classic &c);
};

#endif