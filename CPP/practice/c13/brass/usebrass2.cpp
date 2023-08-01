#include <iostream>
#include "brass.h"
#include <string>

using namespace std;

const int CLIENTS = 3;

int main()
{
        Brass *p[CLIENTS]; //基类指针可以指向基类和派生类对象
        string name_tmp;
        long acct_tmp;
        double bal_tmp;
        int acct_state;

        for (int i = 0; i < CLIENTS; i++)
        {
                cout << "Enter the client's name: ";
                getline(cin, name_tmp);
                cout << "Enter the client's account number: ";
                cin >> acct_tmp;
                cout << "Enter the client's balance: ";
                cin >> bal_tmp;
                cout << "Enter the client's account state(1 for Brass, 2 for BrassPlus): ";
                while ((cin >> acct_state) && (acct_state != 1 && acct_state != 2))
                        cout << "Enter either 1 or 2: ";
                if(acct_state == 1)
                        p[i] = new Brass(name_tmp, acct_tmp, bal_tmp);
                else
                {
                        double tmax, trate;
                        cout << "Enter the client's max loan: ";
                        cin >> tmax;
                        cout << "Enter the client's rate: ";
                        cin >> trate;
                        p[i] = new BrassPlus(name_tmp, acct_tmp, bal_tmp, tmax, trate);
                }
                while (cin.get() != '\n')
                        continue;
        }

        for (int i = 0; i < CLIENTS; i++)
        {
                p[i]->ViewAcct();
                cout << endl;
        }

        for (int i = 0; i < CLIENTS; i++)
        {
                delete p[i];
        }

        return 0;
}