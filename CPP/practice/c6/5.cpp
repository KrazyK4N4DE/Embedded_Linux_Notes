#include<iostream>
using namespace std;

int main()
{
	double income, tax;

	cout << "Enter your income: ";

	while((cin >> income) && (income >= 0))
	{
		if(income <= 5000)
			tax = 0;
		else if(income <= 15000)
			tax = (income - 5000) * 0.1;
		else if(income <= 35000)
			tax = 10000 * 0.1 + (income - 15000) * 0.15;
		else
			tax = 10000 *0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
	cout << "Your tax = " << tax << endl;
	cout << "Enter your income: "; 
	}

	return 0;
}
