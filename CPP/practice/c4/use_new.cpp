#include<iostream>

int main()
{
	using namespace std;

	int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	cout << "nights value = " << nights << ", addr = " << &nights << endl;
	cout << "int value = " << *pt << ", addr = " << pt << endl;

	double* pd = new double;
	*pd = 10000001.0;

	cout << "double value = " << *pd << ", addr = " << pd << endl;
	cout << "Addr of pointer pd = " << &pd << endl;
	cout << "sizeof(pt) = " << sizeof(pt)
	<< "\tsizeof(*pt) = " << sizeof(*pt) << endl;
	cout << "sizeof(pd) = " << sizeof(pd)
	<< "\tsizeof(*pd) = " << sizeof(*pd) << endl;

	return 0;
}
