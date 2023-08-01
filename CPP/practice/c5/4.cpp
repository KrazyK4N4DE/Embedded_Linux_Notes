#include<iostream>
const double Daphne = 0.1;
const double Cleo = 0.05;

int main()
{
	using namespace std;

	int years = 0;
	const double origin = 100;
	double moneyD = 100, moneyC = 100;

	for(; moneyC <= moneyD; years++)
	{
		moneyD += origin * Daphne;
		moneyC *= 1 + Cleo;
	}
	cout << years << " years pass...Cleo's fortune finally excel Daphne's\n"
	<< "Cleo's: " << moneyC << endl
	<< "Daphne's: " << moneyD << endl;

	return 0;
}
