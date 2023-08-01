#include<iostream>

using namespace std;

const int SIZE = 8;

int sum_arr(int [], int);

int main()
{
	int cookies[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};
	cout << cookies << " = array address, \n"
	<< sizeof cookies << " = sizeof cookies\n";

	int sum = sum_arr(cookies, SIZE);
	cout << "Total cookies eaten: " << sum << endl;

	sum = sum_arr(cookies, 3);
	cout << "First 3 cookies eaten: " << sum << endl;

	sum = sum_arr(cookies + 4, 4);
	cout << "Last 4 cookies eaten: " << sum << endl;

	return 0;
}

int sum_arr(int arr[], int n)
{
	int total = 0;
	cout << arr << " = arr, \n"
	<< sizeof arr << " = sizeof arr\n";
	for(int i = 0; i < n; i++)
		total += arr[i];
	return total;
}
