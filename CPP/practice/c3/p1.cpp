#include<iostream>

int main()
{
	using namespace std;

	cout<<"Please enter your height(inches): ___";
	int inch;
	cin>>inch;
	const int index=12;
	cout<<"Height: "<<inch/index<<" feet, "
	<<inch%index<<" inches.\n";

	return 0;
}
