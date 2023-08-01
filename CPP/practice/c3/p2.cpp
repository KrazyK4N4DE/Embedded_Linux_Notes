#include<iostream>
#include<cmath>

const int INCH_TO_FOOT=12;
const float METER_TO_INCH=0.0254f;
const float POUND_TO_KILOGRAM=2.2f;

int main()
{
	using namespace std;

	int feet;
	int inches;
	int pounds;
	cout<<"Enter ur height: \nFeet: ";
	cin>>feet;
	cout<<"Inches: ";
	cin>>inches;
	cout<<"Now enter ur weight: ";
	cin>>pounds;
	int height=feet*INCH_TO_FOOT+inches;
	double meters=height*METER_TO_INCH;
	double kilograms=pounds/POUND_TO_KILOGRAM;
	cout<<feet<<endl<<inches<<endl<<pounds<<endl;
	cout<<"\nHeight: "<<height<<" inches.";
	cout<<"\nMeters: "<<meters<<" meters.";
	cout<<"\nKilograms: "<<kilograms<<" kilograms.\n";
	cout<<"\nBMI index: "<<kilograms/pow(meters, 2)<<endl;

	return 0;
}
