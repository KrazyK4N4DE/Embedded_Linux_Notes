#include<iostream>

using namespace std;

long double prob(unsigned, unsigned);

int main()
{
	double total, choices;
	cout << "Enter the total number of choices on the game card and\n"
	"the number of picks allowed: ";
	while((cin >> total >> choices) && choices <= total)
	{
		/*
		传递double值给unsigned
		*/
		cout << "One chance in " << prob(total, choices) << " of winning.\n"
		"next 2 numbers(q to quit): ";
	}
	cout << "Bye.\n";
	return 0;
}

long double prob(unsigned num, unsigned pick)
{
	long double res = 1;
	long double n;
	for(n = num; pick > 0; n--, pick--)
		res *= (n / pick);
	return res;
}
