#include<iostream>
#include<string>

int main()
{
	using namespace std;

	string name;
	string dessert;

	cout << "Enter your name: \n";
	getline(cin, name);
	cout << "Enter your favorite desssert: \n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert << " for you, " << name << ".\n";

	return 0;
}
