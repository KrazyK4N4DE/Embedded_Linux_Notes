#include<iostream>
#include<string>

int main()
{
	using namespace std;

	cout << "Enter a word: ";
	string word;
	cin >> word;

	for(int i = word.size() - 1; i >= 0; i--)
	{
		cout << word[i];
	}
	cout << "\nBye\n";

	return 0;
}
