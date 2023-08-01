#include<iostream>
#include<string>

int main()
{
	using namespace std;

	char c1[20];
	char c2[20] = "jaguar";
	string s1;
	string s2 = "panther";

	cout << "Enter a kind of feline: ";
	cin >> c1;
	cout << "Enter another: ";
	cin >> s1;
	cout << "Here are some felines: \n";
	cout << c1 << " " << c2 << " " << s1 << " " << s2 << endl;
	cout << "The third letter in " << c2 << " is " << c2[2] << endl;
	cout << "The third letter in " << s2 << " is " << s2[2] << endl;

	return 0;
}
