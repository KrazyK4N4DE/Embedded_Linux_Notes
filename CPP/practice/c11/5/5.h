#ifndef __5_H__
#define __5_H__

#include<iostream>

using namespace std;

class Stonewt
{
public:
        enum Type{STONE, POUNDS, FLOAT_POUNDS};
private:
        //const int n = 10; //不能在类中这样定义常量，因为类只是抽象化
        enum {Lbs_per_stn = 14}; //石头的英镑数
        int stone; //英石
        double pds_left; //除去英石，剩余的英镑数
        double pounds; //英镑数
        Type type;
public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();

        void Set_Type(Type m);

        Stonewt operator+(const Stonewt &s) const;
        Stonewt operator-(const Stonewt &s) const;
        Stonewt operator*(double n) const;

        friend ostream &operator<<(ostream &os, const Stonewt &t);
};

#endif