#include<iostream>
#include<string>
const int months = 12;
const int years = 3;

int main()
{
	using namespace std;

	int sales = 0;
	int total[years] = {0, 0, 0};
	string month[months] = 
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
	int input[years][months];

	for(int j = 0; j < years; j++)
	{
		cout << "*********************************\n" 
		<< "Enter the sales quantity in year " 
		<< j + 1 << " every months: \n";
		for(int i = 0; i < months; i++)
		{
			cout << month[i] << ": ";
			cin >> input[j][i];
			total[j] += input[j][i];
		}
		cout << "This year's sales: " << total[j] << endl;
		sales += total[j];
	}
	cout << endl << "All the sales: " << sales << endl;

	return 0;
}
