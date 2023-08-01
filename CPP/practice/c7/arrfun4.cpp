#include<iostream>

using namespace std;

const int SIZE = 8;

int sum_arr(int*, int*);

int main()
{
	int cookies[SIZE] = {1, 2, 4, 8, 16, 32, 64, 128};
	cout << cookies << " = array address, \n"
	<< sizeof cookies << " = sizeof cookies\n";

	int sum = sum_arr(cookies, cookies + SIZE);
	cout << "Total cookies eaten: " << sum << endl;

	sum = sum_arr(cookies, cookies + 3);
	cout << "First 3 cookies eaten: " << sum << endl;

	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "Last 4 cookies eaten: " << sum << endl;

	return 0;
}

int sum_arr(const int* begin, const int* end)
{
	int total = 0;
	const int* pt;
	for(pt = begin; pt != end; pt++)
		total += *pt;
	return total;
}
