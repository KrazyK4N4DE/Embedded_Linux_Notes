#include<iostream>
const int SIZE = 30;

struct Pizza
{
	char brand[SIZE];
	float diameter;
	float weight;
};

int main()
{
	using namespace std;

	Pizza* info = new Pizza;
	cout << "Diameter: ";
	cin >> info->diameter;
	cin.get();
	cout << "Brand: ";
	cin.getline((*info).brand, SIZE);
	cout << "Weight: ";
	cin >> info->weight;

	cout << "\nBrand: " << info->brand
	<< "\nDiameter: " << info->diameter
	<< "\nWeight: " << info->weight << endl; 

	delete info;

	return 0;
}
