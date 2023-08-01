#ifndef __BRASS_H__
#define __BRASS_H__

#include <iostream>
#include <cstring>

using namespace std;

class Brass
{
private:
        string fullname;
        long acctNum;
        double balance;
public:
        Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const;
        virtual void ViewAcct() const;
        virtual ~Brass(){}
};

class BrassPlus : public Brass
{
private:
        double maxLoan; //最大透支
        double rate; //透支利率
        double owesBank; //本金加利息一共欠银行的钱
public:
        BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0, 
        double ml = 500.0, double rate = 0.011125);
        BrassPlus(const Brass &ba, double ml = 500.0, double rate = 0.011125);
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) {maxLoan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes() {owesBank = 0.0;}
};

#endif