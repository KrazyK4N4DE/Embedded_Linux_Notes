#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

struct donate
{
	string name;
	double donation;
};

int main()
{
	int num = 0;
	bool empty = true;

	ifstream inf;
	string filename;
	cout << "Enter file name: ";
	getline(cin, filename);
	inf.open(filename);
	if(!inf.is_open())
	{
		cout << "Failed to open!\n";
		exit(EXIT_FAILURE);
	}

	inf >> num;
	if(num <= 0)
	{
		cout << "The amount of donors can't be under 0 (Include 0)!\n";
		exit(EXIT_FAILURE);
	}
	donate* donors = new donate[num];
	inf.get();

	int i = 0;
	while((!inf.eof()) && (i < num))
	{
		cout << "********************************\n";
		getline(inf, donors[i].name);
		cout << "Read name: " << donors[i].name << "\n";
		inf >> donors[i].donation;
		cout << "Read donation: " << donors[i].donation << "\n";
		i++;
		inf.get();
	}

	cout << "------- Grand Donors -------\n";
	for(int j = 0; j < num; j++)
	{
		if(donors[j].donation >= 10000)
		{
			cout << donors[j].name << ": " << donors[j].donation << endl;
			empty = false;
		}
	}
	if(empty)
		cout << "None\n";

	empty = true;

	cout << "------- Donors -------\n";
	for(int j = 0; j < num; j++)
	{
		if(donors[j].donation < 10000)
		{
			cout << donors[j].name << ": " << donors[j].donation << endl;
			empty = false;
		}
	}
	if(empty)
		cout << "None\n";

	delete[] donors;

	return 0;
}
