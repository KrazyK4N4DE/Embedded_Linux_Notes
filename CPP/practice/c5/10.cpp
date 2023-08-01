#include<iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter number of rows: ";
	cin >> num;

	for(int i = 1; i <= num; i++)
	{
		for(int j = 0; j < num - i; j++)
		{
			cout << ".";
		}
		for(int k = num - i; k < num; k++)
		{
			cout << "*";
		}
	cout << endl;
	}

	return 0;
}
