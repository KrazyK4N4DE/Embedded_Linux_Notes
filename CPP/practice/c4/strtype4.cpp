#include<iostream>
#include<string>
#include<cstring>

int main()
{
	using namespace std;
	char c[20];
	string s;

	cout << "Length of string in c before input: " << strlen(c) << endl;
	cout << "Length of string in s before input: " << s.size() << endl;
	cout << "Enter a line of text:\n";
	cin.getline(c, 20);
	cout << "You entered: " << c << endl;
	cout << "Enter another line of text:\n";
	getline(cin, s);
	cout << "You entered: " << s << endl;
	cout << "Length of c after input: " << strlen(c) << endl;
	cout << "Length of s after input: " << s.size() << endl;

	return 0;
}
