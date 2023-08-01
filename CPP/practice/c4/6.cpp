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

	CandyBar snack[3] = 
	{
		{"Mocha Munch", 2.3, 350},
		{"What the fxxk", 1.6, 440},
		{"Candik", 3.1, 190}
	};

	int i = 0;
	for(;i<3;i++)
	{
		cout << "\nBrand: " << snack[i].brand
		<< "\nWeight: " << snack[i].weight
		<< "\nCalorie: " << snack[i].calorie << endl;
	}

	return 0;
}

