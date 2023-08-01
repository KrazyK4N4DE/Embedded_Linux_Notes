#include<iostream>

int main()
{
	using namespace std;

	double wage[3] = {10000.0, 20000.0, 30000.0};
	short stack[3] = {3,2,1};
	double* pw = wage;
	short* ps = &stack[0];

	cout << "pw: " << pw << ", *pw: " << *pw << endl;
	pw += 1;
	cout << "pw add 1 to pointer:\n";
	cout << "pw: " << pw << ", *pw: " << *pw << endl;
	cout << "ps: " << ps << ", *ps: " << *ps << endl;
	ps += 1;
	cout << "ps: " << ps << ", *ps: " << *ps << endl;

	cout << "Access 2 elements with array notation\n";
	cout << "stack[0]: " << stack[0] << ", stack[1]: " << stack[1] <<endl;
	cout << "Pointer\n";
	cout << "*stcak: " << *stack << ", *(stack + 1): " << *(stack + 1) << endl;

	cout << sizeof(wage) << " = size of wage array\n";
	cout << sizeof(pw) << " = size of pw pointer\n";

	return 0;
}
