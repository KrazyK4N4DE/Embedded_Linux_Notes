#include <iostream>
#include "brass.h"

using namespace std;

int main()
{
        Brass Rick("Rick", 123456, 4000.00);
        BrassPlus Jack("Jack", 123457, 3000.00);

        Rick.ViewAcct();
        cout << endl;
        Jack.ViewAcct();
        cout << endl;

        cout << "Desposting $1000 into Jack's account: \n";
        Jack.Deposit(1000.00);
        cout << "New balance: $" << Jack.Balance() << endl;

        cout << "Withdrawing $4200 from Rick's account: \n";
        Rick.Withdraw(4200.00);

        cout << "Withdrawing $4200 from Jack's account: \n";
        Jack.Withdraw(4200.00);
        Jack.ViewAcct();

        return 0;
}