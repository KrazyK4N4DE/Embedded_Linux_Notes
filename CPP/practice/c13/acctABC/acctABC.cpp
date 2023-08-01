#include "acctABC.h"

AcctABC::AcctABC(const string &s, long an, double bal)
{
        fullname = s;
        acctNum = an;
        balance = bal;
}

void AcctABC::Deposit(double amt)
{
        if (amt < 0)
                cout << "Negative deposit not allowed!" << endl;
        else
                balance += amt;
}

void AcctABC::Withdraw(double amt)
{
        balance -= amt;
}

void Brass::Withdraw(double amt)
{
        if (amt < 0)
                cout << "Withdrawal amount must be positive!" << endl;
        else if(Balance() < amt)
                cout << "Withdrawal amount of $" << amt << " exceeds your balance!" << endl;
        else
                AcctABC::Withdraw(amt);
}

void Brass::ViewAcct() const
{
        cout << "Client: " << Fullname() << endl;
        cout << "Account Number: " << AcctNum() << endl;
        cout << "Balance : $" << Balance() << endl;
}

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
        maxLoan = ml;
        rate = r;
        owesBank = 0.0;
}

BrassPlus::BrassPlus(const AcctABC &ba, double ml, double r) : AcctABC(ba)
{
        maxLoan = ml;
        rate = r;
        owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
        cout << "Client: " << Fullname() << endl;
        cout << "Account Number: " << AcctNum() << endl;
        cout << "Balance : $" << Balance() << endl;
        cout << "Maximum loan: $" << maxLoan << endl;
        cout << "Owed to bank: $" << owesBank << endl;
        cout << "Loan Rate: " << 100 * rate << "%" << endl;
}

void BrassPlus::Withdraw(double amt)
{
        double bal = Balance();
        if (amt <= bal)
                AcctABC::Withdraw(amt);
        else if (amt <= bal + maxLoan - owesBank)
        {
                double advance = amt - bal;
                owesBank = advance * (1.0 + rate);
                cout << "Bank advance: $" << advance << endl; //透支了多少
                cout << "Finance charge: $" << advance * rate << endl; //手续费(利息)
                Deposit(advance);
                AcctABC::Withdraw(amt);
        }
        else
                cout << "Credit limit exceeded. Transaction cancelled." << endl;
}