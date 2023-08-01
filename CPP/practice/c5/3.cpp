#include<iostream>

int main()
{
	using namespace std;

	int num, total = 0;

	cout << "Enter the num: ";
	cin >> num;
	while(num)
	{
		total += num;
		cout << "Sum: " << total << endl;
		cout << "Again: ";
		cin >> num;
	}

	return 0;
}
