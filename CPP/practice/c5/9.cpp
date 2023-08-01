#include<iostream>
#include<string>
using namespace std;
const char DONE[] = "done";

int main()
{
	string words;
	int count;
	cout << "Enter words (to stop, type the word \"done\"):\n";

	do
	{
		cin >> words;
		//cin.get();
		count++;
	}
	while(words != DONE);
	cout << "You enter a total of " << count - 1 << " words.\n";

	return 0;
}
