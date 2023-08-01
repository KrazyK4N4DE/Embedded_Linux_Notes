#include<iostream>

int main()
{
	using namespace std;

	int x, y, total = 0;
	cout << "Enter the smaller number: ";
	cin >> x;
	cout << "Larger one: ";
	cin >> y;

	for(int i = x; i <= y; i++)
	{
		total += i;
	}
	cout << "The sum between " << x << " and " << y << "(including themselves): " 
	<< total << endl;

	return 0;
}
