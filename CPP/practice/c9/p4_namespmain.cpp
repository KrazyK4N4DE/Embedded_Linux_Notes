#include<iostream>
#include "p4_namesp.h"

int main()
{
        using debts::Debt;
        using debts::showDebt;

        Debt golf = {{"Benny", "Goatsniff"}, 120.0};
        showDebt(golf);

        return 0;
}