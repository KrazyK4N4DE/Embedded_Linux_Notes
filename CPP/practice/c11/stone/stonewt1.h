#ifndef __STONEWT1_H__
#define __STONEWT1_H__

#include<iostream>

using namespace std;

class Stonewt
{
private:
        //const int n = 10; //不能在类中这样定义常量，因为类只是抽象化
        enum {Lbs_per_stn = 14}; //石头的英镑数
        int stone; //英石
        double pds_left; //除去英石，剩余的英镑数
        double pounds; //英镑数
public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        void ShowLbs() const;
        void ShowStn() const;
        operator int() const;
        operator double() const;
};

#endif