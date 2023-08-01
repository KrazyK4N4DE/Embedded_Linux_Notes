#include<iostream>

struct CandyBar
{
	char brand[20];
	double weight;
	int calorie;
};

int main()
{
	using namespace std;

	CandyBar snack = 
	{
		"Mocha Munch",
		2.3,
		350
	};

	cout << "Brand: " << snack.brand
	<< "\nWeight: " << snack.weight
	<< "\nCalorie: " << snack.calorie << endl;

	return 0;
}

