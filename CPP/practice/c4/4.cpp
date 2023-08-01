#include<iostream>
#include<string>

int main()
{
	using namespace std;

	string first, last, full;

	cout << "first name: ";
	getline(cin, first);
	cout << "last name: ";
	getline(cin, last);

	full = last + ", " + first;

	cout << "Information in a single string: " << full << endl;
	
	return 0;
}
