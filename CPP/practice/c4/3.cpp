#include<iostream>
#include<cstring>
const int SIZE = 20;

int main()
{
	using namespace std;

	char first[SIZE], last[SIZE], full[2*SIZE + 2];

	cout << "first name: ";
	cin.get(first, SIZE).get();
	cout << "last name: ";
	cin.getline(last, SIZE);

	strcpy(full, last);
	strcat(full, ", ");
	strcat(full, first);

	cout << "Information in a single string: " << full << endl;
	
	return 0;
}
