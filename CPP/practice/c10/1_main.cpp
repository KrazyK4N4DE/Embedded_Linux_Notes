#include"1.h"

int main()
{
        BankAccount n1;
        n1.show();

        cout << "***************************************" << endl;
        n1.deposit(500);
        cout << "国家研究生补助500元到账! " << endl;
        n1.show();

        cout << "***************************************" << endl;
        n1.withdraw(5);
        cout << "充电结束!" << endl;
        n1.show();

        return 0;
}