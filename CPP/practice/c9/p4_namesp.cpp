#include<iostream>
#include"p4_namesp.h"

namespace pers
{
        using std::cout;
        using std::cin;
        
        void getPerson(Person &rp)
        {
                cout << "Enter first name: ";
                cin >> rp.first;
                cout << "Enter last name: ";
                cin >> rp.last;
        }
        void showPerson(const Person &rp)
        {
                cout << rp.first << " " << rp.last;
        }
}

namespace debts
{
        using namespace pers;

        
        void getDebt(Debt &rd)
        {
                getPerson(rd.name);
                std::cout << "Enter debt: ";
                std::cin >> rd.amount;
        }
        void showDebt(const Debt &rd)
        {
                showPerson(rd.name);
                std::cout << ": $" << rd.amount << std::endl;
        }
        double sumDebts(const Debt ar[], int n)
        {
                double total = 0;
                for(int i = 0; i < n; i++)
                        total += ar[i].amount;
                return total;
        }
}