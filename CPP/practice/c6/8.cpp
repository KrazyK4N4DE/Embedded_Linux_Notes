#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
	ifstream fp;
	cout << "Enter file name: ";
	string filename;
	getline(cin, filename);
	fp.open(filename);
	if(!fp.is_open())
	{
		cout << "Fail to open file!\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	int count;
	while(!fp.eof())
	{
		fp >> ch;
		count++;
	}

	cout << filename << " has " << count << " characters.\n";

	fp.close();

	return 0;
}
