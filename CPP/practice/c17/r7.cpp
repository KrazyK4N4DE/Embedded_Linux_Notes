#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
        string name;
        double hourly, hours;

        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter houtly wages: ";
        cin >> hourly;
        cout << "Enter number of hours worked: ";
        cin >> hours;

        cout << "First format:\n";
        cout << showpoint << fixed;  // fixed：不想使用科学计数法；showpoint：显示小数点后的0
        cout << setw(25) << name << ": $" 
        << setw(13) << setprecision(2) << hourly << ":"
        << setw(7) << setprecision(1) << hours << endl;

        cout << "Second format:\n";
        cout << left;  // 左对齐
        cout << setw(25) << name << ": $" 
        << setw(13) << setprecision(2) << hourly << ":"
        << setw(7) << setprecision(1) << hours << endl;

        return 0;
}