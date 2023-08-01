#ifndef __ACCTABC_H__
#define __ACCTABC_H__

#include <iostream>
#include <cstring>

using namespace std;

// 抽象基类
class AcctABC
{
private:
        string fullname;
        long acctNum;
        double balance;
protected:
        const string &Fullname() const {return fullname;}
        long AcctNum() const {return acctNum;}
public:
        AcctABC(const string &s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt) = 0;
        double Balance() const {return balance;}
        virtual void ViewAcct() const = 0;
        virtual ~AcctABC() {}
};

// 具体类
class Brass : public AcctABC
{
public:
        Brass(const string &s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) {}
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        virtual ~Brass(){}
};

class BrassPlus : public AcctABC
{
private:
        double maxLoan; //最大透支
        double rate; //透支利率
        double owesBank; //本金加利息一共欠银行的钱
public:
        BrassPlus(const string &s = "Nullbody", long an = -1, double bal = 0.0, 
        double ml = 500.0, double rate = 0.011125);
        BrassPlus(const AcctABC &ba, double ml = 500.0, double rate = 0.011125);
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) {maxLoan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes() {owesBank = 0.0;}
};

#endif