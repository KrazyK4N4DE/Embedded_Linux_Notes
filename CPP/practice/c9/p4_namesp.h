/*
结构和函数原型放在头文件
*/
#ifndef P4_NAMESP_H_
#define P4_NAMESP_H_

#include<string>

namespace pers
{
        struct Person
        {
                std::string first;
                std::string last;
        };

        void getPerson(Person &rp);
        void showPerson(const Person &rp);
}

namespace debts
{
        using namespace pers;

        struct Debt
        {
                Person name;
                double amount;
        };

        void getDebt(Debt &rd);
        void showDebt(const Debt &rd);
        double sumDebts(const Debt ar[], int n);
}

#endif