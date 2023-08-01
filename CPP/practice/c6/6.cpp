#include<iostream>
#include<string>

using namespace std;

struct donate
{
	string name;
	double money;
};

int main()
{
	cout << "Enter the amount of the patrons: ";
	int amount;
	cin >> amount;
	while((amount <= 0) || cin.fail())
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "Please enter a positive integer: ";
		cin >> amount;
	}
	cin.get();
	donate* donor = new donate[amount];

	for(int i = 0; i < amount; i++)
	{
		cout << "-----------------------------------\n"
		<< "donor #" << i + 1 << ": \n"
		<< "Enter the name: ";
		getline(cin, donor[i].name);
		cout << "Enter the donation amount: ";
		cin >> donor[i].money;
		cin.get();
	}
	cout << "-----------------------------------\n\n"
	<< "******* Grand Patrons *******\n";

	bool empty_gp = true, empty_p = true;
	for(int i = 0; i < amount; i++)
	{
		if(donor[i].money >= 10000)
		{
			cout << donor[i].name << ": " << donor[i].money << endl; 
			empty_gp = false;
		}
	}
	if(empty_gp)
		cout << "None" << endl;

	cout << "\n------- Patrons -------\n";
	for(int i = 0; i < amount; i++)
	{
		if(donor[i].money < 10000)
		{
			cout << donor[i].name << ": " << donor[i].money << endl; 
			empty_p = false;
		}
	}
	if(empty_p)
		cout << "None\n";

	return 0;
}
