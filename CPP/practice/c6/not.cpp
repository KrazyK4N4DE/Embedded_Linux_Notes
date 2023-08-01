#include<iostream>
#include<climits>		//For INT_MAX and INT_MIN
using namespace std;
bool is_int(double);

int main()
{
	double num;
	cout << "Enter an integer value: ";
	cin >> num;
	while(!is_int(num))
	{
		cout << "Out of range!\nTry again: ";
		cin >> num;
	}
	cout << "You have entered the integer " << int (num) << endl;

	return 0;
}

bool is_int(double x)
{
	if(x <= INT_MAX && x >= INT_MIN)
		return true;
	else
		return false;
}
