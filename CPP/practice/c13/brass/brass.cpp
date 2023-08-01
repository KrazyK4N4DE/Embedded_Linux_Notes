#include "brass.h"

Brass::Brass(const string &s, long an, double bal)
{
        fullname = s;
        acctNum = an;
        balance = bal;
}

void Brass::Deposit(double amt)
{
        if (amt < 0)
                cout << "Negative deposit not allowed!" << endl;
        else
                balance += amt;
}

void Brass::Withdraw(double amt)
{
        if (amt < 0)
                cout << "Withdrawal amount must be positive!" << endl;
        else if(balance < amt)
                cout << "Withdrawal amount of $" << amt << " exceeds your balance!" << endl;
        else
                balance -= amt;
}

double Brass::Balance() const
{
        return balance;
}

void Brass::ViewAcct() const
{
        cout << "Client: " << fullname << endl;
        cout << "Account Number: " << acctNum << endl;
        cout << "Balance : $" << balance << endl;
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
        maxLoan = ml;
        rate = r;
        owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass(ba)
{
        maxLoan = ml;
        rate = r;
        owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
        Brass::ViewAcct();
        cout << "Maximum loan: $" << maxLoan << endl;
        cout << "Owed to bank: $" << owesBank << endl;
        cout << "Loan Rate: " << 100 * rate << "%" << endl;
}

void BrassPlus::Withdraw(double amt)
{
        double bal = Balance();
        if (amt <= bal)
                Brass::Withdraw(amt);
        else if (amt <= bal + maxLoan - owesBank)
        {
                double advance = amt - bal;
                owesBank = advance * (1.0 + rate);
                cout << "Bank advance: $" << advance << endl; //透支了多少
                cout << "Finance charge: $" << advance * rate << endl; //手续费(利息)
                Deposit(advance);
                Brass::Withdraw(amt);
        }
        else
                cout << "Credit limit exceeded. Transaction cancelled." << endl;
}