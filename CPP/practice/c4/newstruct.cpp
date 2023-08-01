#include<iostream>

struct inf
{
	char name[20];
	float vol;
	double price;
};
int main()
{
	using namespace std;

	inf* ps = new inf;
	cout << "Enter name of inf: ";
	cin.get(ps->name, 20);
	cout << "Enter vol: ";
	cin >> (*ps).vol;
	cout << "Enter price: $";
	cin >> ps->price;
	cout << "Name: " << (*ps).name << endl;
	cout << "Vol: " << (*ps).vol << endl;
	cout << "Price: " << ps->price << endl;
	delete ps;

	return 0;
}
