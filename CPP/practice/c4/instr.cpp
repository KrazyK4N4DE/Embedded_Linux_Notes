#include<iostream>

const int SIZE=20;

int main()
{
	using namespace std;

	char name[SIZE];
	char dessert[SIZE];
	cout << "Enter your name: \n";
//	cin >> name;
//	cin.getline(name, SIZE);
	cin.get(name,SIZE).get();
	cout << "Enter your favorite desssert: \n";
//	cin >> dessert;
//	cin.getline(dessert, SIZE);
	cin.get(dessert,SIZE).get();
	cout << "I have some delicious " << dessert << " for you, " << name << ".\n";

	return 0;
}
