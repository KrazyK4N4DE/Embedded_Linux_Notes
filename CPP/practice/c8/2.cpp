#include<iostream>
#include<cstring>
using namespace std;

struct CandyBar
{
        char name[20];
        double weight;
        int calories;
};

void Set_Value(CandyBar &bar, const char *name, const double weight, const int calories);
void show(const CandyBar &bar);

int main()
{
        CandyBar bar;
        Set_Value(bar, "Millennium Munch", 2.85, 350);
        show(bar);

        return 0;
}

void Set_Value(CandyBar &bar, const char *name, const double weight, const int calories)
{
        strcpy(bar.name, name);
        bar.weight = weight;
        bar.calories = calories;
}

void show(const CandyBar &bar)
{
        cout << "Name: " << bar.name << endl;
        cout << "Weight: " << bar.weight << endl;
        cout << "Calories: " << bar.calories << endl;
}