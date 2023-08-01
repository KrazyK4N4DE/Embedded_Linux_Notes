#include<iostream>
#include<array>

using namespace std;

const int SEASON = 4;
array<string, SEASON> snames = {"Spring", "Summer", "Fall", "Winter"};

void fill(array<double,SEASON> *pa);
void show(array<double,SEASON> da);

int main()
{
        array<double, SEASON> expenses;
        
        fill(&expenses);
        show(expenses);

        return 0;
}

void fill(array<double,SEASON> *pa)
{
        for(int i = 0; i<SEASON; i++)
        {
                cout << "Enter " << snames[i]
                << " expenses: ";
                cin >> (*pa)[i];
                //pa是array对象指针，不是array对象；array对象可以像数组一样使用，从来没说过array对象的指针可以像数组一样操作
        }
}

void show(array<double,SEASON> da)
{
        double total = 0.0;
        for(int i = 0; i < SEASON; i++)
        {
                cout << snames[i] << ": $" << da[i] << endl;
                total += da[i]; 
        }
        cout << "Total Expenses: $" << total << endl;
}
