#include<iostream>

using namespace std;
void showmenu();
void eatline();
void print_by_fullname();
void print_by_title();
void print_by_bopname();
void print_by_preference();

const int SIZE = 30;
const int USRMAX = 4;

struct bop
{
	char fullname[SIZE];	// real name
	char title[SIZE];	// job title
	char bopname[SIZE];	// secret BOP name
	int preference;		// 0 = fullname, 1 = title, 2 = bopname
};
bop users[USRMAX] = 
{
	{"Rick", "Lvl_A", "RR", 0},
	{"Jack", "Lvl_B", "JJ", 1},
	{"Mike", "Lvl_C", "MM", 2},
	{"Rose", "Lvl_D", "RR", 0},
};

int main()
{
	showmenu();
	cout << "Enter your choice: ";
	char input;
	cin.get(input);

	while(input != 'q')
	{
		switch(input)
		{
			case 'a': print_by_fullname(); break;
			case 'b': print_by_title(); break;
			case 'c': print_by_bopname(); break;
			case 'd': print_by_preference(); break;
			default: cout << "Enter the correct letter!\n";
		}
		eatline();
		cout << "Next input: ";
		cin.get(input);
	}
	cout << "****************************************\nDONE\n";

	return 0;
}

void showmenu()
{
	cout << "Benevolent Order of Programmers Report\n"
	<< "------------------------------------------------\n"
	<< "a. Display by name\tb. Display bytitle\n"
	<< "c. Display by bopname\td. Display by preference\n"
	<< "q. Quit\n"
	<< "------------------------------------------------\n";
}

void eatline()
{
	while(cin.get() != '\n')
		continue;
}

void print_by_fullname()
{
	for(int i = 0; i < USRMAX; i++)
		cout << users[i].fullname << endl;
}

void print_by_title()
{
	for(int i = 0; i < USRMAX; i++)
		cout << users[i].title << endl;
}

void print_by_bopname()
{
	for(int i = 0; i < USRMAX; i++)
		cout << users[i].bopname << endl;
}

void print_by_preference()
{
	for(int i = 0; i < USRMAX; i++)
		switch(users[i].preference)
		{
			case 0: cout << users[i].fullname << endl; break;
			case 1: cout << users[i].title << endl; break;
			case 2: cout << users[i].bopname << endl; break;
		}
}
