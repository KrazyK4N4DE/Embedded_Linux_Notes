#include<iostream>
const int SIZE = 30;

struct Pizza
{
	char brand[SIZE];
	float diameter;
	float weight;
}info;

int main()
{
	using namespace std;

	cout << "Brand: ";
	cin.getline(info.brand, SIZE);
	cout << "Diameter: ";
	cin >> info.diameter;
	cout << "Weight: ";
	cin >> info.weight;

	cout << "\nBrand: " << info.brand
	<< "\nDiameter: " << info.diameter
	<< "\nWeight: " << info.weight << endl; 

	return 0;
}
