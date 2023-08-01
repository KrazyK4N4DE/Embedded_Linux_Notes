/*
银行类方法源代码
*/
#include<iostream>
#include<cstring>
#include "1.h"

BankAccount::BankAccount(const string client, const string num, double money)
{
        name = client;
        accountnum = num;
        balance = money;
}

void BankAccount::show() const
{
        cout << "Name: " << name << endl;
        cout << "Account number: " << accountnum << endl;
        cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double money)
{
        balance += money;
        cout << "Deposit $" << money << " successfully!" << endl;
}
void BankAccount::withdraw(double money)
{
        balance -= money;
        cout << "Withdraw $" << money << " successfully!" << endl;
}

