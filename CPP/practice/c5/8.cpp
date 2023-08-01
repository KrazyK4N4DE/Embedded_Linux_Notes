#include<iostream>
#include<cstring>
using namespace std;
const char DONE[] = "done";
int main()
{
	char words[20];
	int count;
	cout << "Enter words (to stop, type the word \"done\"):\n";

	do
	{
		cin >> words;
		//cin.get();
		count++;
	}
	while(strcmp(words, DONE) != 0);
	cout << "You enter a total of " << count - 1 << " words.\n";

	return 0;
}
