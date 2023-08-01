#include<iostream>
const int D_TO_M=60;
const int D_TO_S=3600;

int main()
{
	using namespace std;

	int degrees, minutes, seconds;
	cout<<"Enter the degrees: ";
	cin>>degrees;
	cout<<"Enter the minutes of arc: ";
	cin>>minutes;
	cout<<"Enter the seconds of arc: ";
	cin>>seconds;
	double total;
	total=degrees+((double)minutes)/D_TO_M+((double)seconds)/D_TO_S;
	cout<<degrees<<" degrees, "
	<<minutes<<" minutes, "
	<<seconds<<" seconds = "
	<<total<<" degrees\n";

	return 0;
}
