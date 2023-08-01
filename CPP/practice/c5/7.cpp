#include<iostream>
#include<string>
struct Car
{
	std::string brand;
	int year;
};

int main()
{
	using namespace std;

	cout << "How many cars do you wish to catalog? ";
	int num;
	cin >> num;
	cin.get();
	Car* info = new Car[num];
	for(int i = 0; i < num; i++)
	{
		cout << "Car #" << i + 1 << ":\n";
		cout << "Enter the make: ";
		getline(cin, (info + i)->brand);
		cout << "Enter the year made: ";
		cin >> (info + i)->year;
		cin.get();
	}
	cout << "Here is your collection:\n";
	for(int i = 0; i < num; i++)
	{
		cout << (info + i)->year << "  " << (info + i)->brand << endl;
	}
	delete[] info;

	return 0;
}
