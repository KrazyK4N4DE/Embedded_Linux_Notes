#include<iostream>
#include<cctype>

int main()
{
	using namespace std;

	cout << "Enter text for analysis and type @ to teminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;
	cin.get(ch);

	while(ch != '@')
	{
		if(isalpha(ch))
			chars++;
		else if(isspace(ch))
			whitespace++;
		else if(isdigit(ch))
			digits++;
		else if(ispunct(ch))
			punct++;
		else
			others++;
		cin.get(ch);
	}

	cout << chars << " letters, "
	<< whitespace << " whitespace, "
	<< digits << " digits, "
	<< punct << " punctuations, "
	<< others << " others.\n";

	return 0;
}
