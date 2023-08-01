/*
有关银行的数据与操作的类头文件
*/
#ifndef __1_H__
#define __1_H__

#include<iostream>
#include<string>

using namespace std;

class BankAccount
{
private:
        string name;
        string accountnum;
        double balance;
public:
        BankAccount(const string client = "WeiWei", const string num = "TS21050065A31", double money = 139.57);
        void show() const;
        void deposit(double money);
        void withdraw(double money);
};

#endif