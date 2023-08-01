#include<iostream>
#include<string>
using namespace std;

int main()
{
	string line;
	int space = 0;

	cout << "Enter a line of text: ";
	getline(cin, line);
	cout << "Complete line:\n" << line << endl
	<< "Line through first period: \n";

	for(int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];
		if(line[i] == '.')
			break;
		if(line[i] != ' ')
			continue;
		space++;
	}

	cout << "\n" << space << " spaces\n";

	return 0;
}
