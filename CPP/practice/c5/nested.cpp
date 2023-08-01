#include<iostream>
const int Cities = 5;
const int Years = 4;

int main()
{
	using namespace std;

	const char* cities[Cities] = 
	{
		"Shanghai",
		"Beijing",
		"Guangzhou",
		"Nanning",
		"Chongqing"
	};

	int maxtemps[Years][Cities] = 
	{
		{37, 34, 38, 37, 36},
		{37, 38, 36, 33, 39},
		{39, 35, 38, 31, 38},
		{41, 37, 39, 35, 40}
	};

	cout << "Maximum tempertures for 2008 - 2011\n\n";
	for(int city=0;city<Cities;city++)
	{
		cout << cities[city] << ":\t";
		for(int year=0;year<Years;year++)
		{
			cout << maxtemps[year][city] << "\t";
		}
		cout << endl;
	}

	return 0;
}
