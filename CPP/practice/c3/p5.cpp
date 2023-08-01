#include<iostream>

int main()
{
	using namespace std;

	long long world, us;
	cout<<"Enter the world's population: ";
	cin>>world;
	cout <<"Enter the population of the US: ";
	cin>>us;
	long double percentage;
	percentage=(long double)us/(long double)world*100;
	cout<<"The population of the US is "<<percentage<<"\% of the world population.\n";

	return 0;

}
