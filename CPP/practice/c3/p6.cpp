#include<iostream>

int main()
{
	using namespace std;

	double consume, mile, gal, km, lit;
	cout<<"Enter the mileage in miles: ";
	cin>>mile;
	cout<<"Enter the fuel in gallon: ";
	cin>>gal;
	consume=mile/gal;
	cout<<"Consume: "<<consume<<"miles/gallon\n";

	cout<<"Enter the mileage in kilometers: ";
	cin>>km;
	cout<<"Enter the fuel in liter: ";
	cin>>lit;
	consume=100*(lit/km);
	cout<<"Consume: "<<consume<<"L/100km\n";
	
	return 0;
}
