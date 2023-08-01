#include<iostream>

int main()
{
	using namespace std;
	
	cout << "What year was your house built?\n";
	int year;
	cin >> year;
	cin.get();
	cout << "What is its street address?\n";
	char addr[80];
	cin.get(addr, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << addr << endl;
	cout << "Done.\n";

	return 0;
}
