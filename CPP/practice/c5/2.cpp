#include<iostream>
#include<array>
const int SIZE = 101;

int main()
{
	using namespace std;

	array<long double, SIZE> fac;
	fac[0] = fac[1] = 1L;
	for(int i = 2; i < SIZE; i++)
	{
		fac[i] = i * fac[i-1];
	}
	cout << "100! = " << fac[100] <<endl;

	return 0;
}
