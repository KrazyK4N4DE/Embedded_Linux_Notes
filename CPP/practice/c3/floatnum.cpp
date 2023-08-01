#include<iostream>

int main()
{
	using namespace std;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tub=10.0/3.0;
	double mint=10.0/3.0;
	const float million=1.0e6;

	cout<<"tub = "<<tub<<", a million tubs = "<<million*tub<<endl;
	cout<<"And ten millon tubs = "<<10*million*tub<<endl;
	cout<<"mint = "<<mint<<", amillion mints = "<<million*mint<<endl;

	return 0;
}
