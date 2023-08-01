#include<iostream>
#include<string>
const int months = 12;

int main()
{
	using namespace std;

	int sales;
	const string month[months] = 
	{
		"January",
		"Febuary",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int input[months];

	cout << "Enter the sales quantity every months: \n";
	for(int i = 0; i < months; i++)
	{
		cout << month[i] << ": ";
		cin >> input[i];
		sales += input[i];
	}
	cout << endl << "All the sales: " << sales << endl;

	return 0;
}
