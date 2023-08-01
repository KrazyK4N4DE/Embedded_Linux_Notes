#include<iostream>
using namespace std;

void showmenu();
void eatline();

int main()
{
	showmenu();
	char ch;
	cin.get(ch);

	while(ch != 'c' && ch != 'p' && ch != 't' && ch != 'g')
	{
		eatline();
		cout << "Enter the correct letter: ";
		cin.get(ch);
	}
	switch(ch)
	{
		case 'c':
			cout << "Carnivore I don't know!\n";
			break;
		case 'p':
			cout << "I am not a pianist.\n";
			break;
		case 't':
			cout << "A maple is a tree.\n";
			break;
		case 'g':
			cout << "Game over!\n";
			break;
	}

	return 0;
}

void showmenu()
{
	cout << "Enter one of the following choices:\n"
	<< "-----------------------------------\n"
	<< "c) carnivore\t\tp) pianist\n"
	<< "t) tree\t\t\tg) game\n"
	<< "-----------------------------------\n";
}

void eatline()
{
	while(cin.get() != '\n')
		continue;
}
