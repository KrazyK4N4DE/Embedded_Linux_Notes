#include<iostream>
#include<cctype>

int main()
{
	using namespace std;

	char ch;
	cout << "Enter a text(ytpe '@' to terminate):\n";
	while((ch = cin.get()) != '@')
	{
		if(isdigit(ch))
		{
			continue;
		}
		else if(isalpha(ch))
		{
			if(islower(ch))
				cout << (char) toupper(ch);
			else if(isupper(ch))
				cout << (char) tolower(ch);
		}
		else
			cout << ch;
	}
	cout << endl;

	return 0;
}
