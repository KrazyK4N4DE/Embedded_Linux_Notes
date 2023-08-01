#include<iostream>

int main(void)
{
	using namespace std;

	char ch;
	int count = 0;

	cout << "Enter characters(Enter '#' to quit):\n";
	cin >> ch;

	while(ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}

	cout << endl << count << " characters read.\n";

	return 0;
}
