#include<iostream>
#include<cstring>

struct CandyBar
{
	char brand[20];
	double weight;
	int calorie;
};

int main()
{
	using namespace std;

	CandyBar* snack = new CandyBar[3];

	strcpy(snack[0].brand, "Mocha Munch");
	snack[0].weight = 2.3;
	snack[0].calorie = 350;

	strcpy(snack[1].brand, "Tha fxxk");
	snack[1].weight = 1.6;
	snack[1].calorie = 770;

	strcpy(snack[2].brand, "Candik");
	snack[2].weight = 4.9;
	snack[2].calorie = 189;

	int i = 0;
	for(;i<3;i++)
	{
		cout << "\nBrand: " << (snack + i)->brand
		<< "\nWeight: " << (snack + i)->weight
		<< "\nCalorie: " << (snack + i)->calorie << endl;
	}

	delete[] snack;

	return 0;
}
