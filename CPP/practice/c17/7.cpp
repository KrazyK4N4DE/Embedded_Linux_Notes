#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void ShowStr(const string &s);
void GetStrs(ifstream &is, vector<string> &vs);

class Store
{
private:
	ofstream &fo;
public:
	Store(ofstream &os) : fo(os) {}
	void operator()(const string &s);  // 仿函数必须要有括号重载
};

void Store::operator()(const string &s)
{
	size_t len = s.size();
	fo.write((char *)&len, sizeof(size_t));
	fo.write(s.data(), len);
}

int main(void)
{
	vector<string> vostr;
    	string temp;

    	cout << "Enter string (empty line to quit): \n";
    	while (getline(cin, temp) && temp[0] != '\0')
        	vostr.push_back(temp);
    	cout << "Here is your input.\n";
    	for_each(vostr.begin(), vostr.end(), ShowStr);

    	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    	for_each(vostr.begin(), vostr.end(), Store(fout));
    	fout.close();

    	vector<string> vistr;
    	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    	if (!fin.is_open())
    	{
        	cerr << "Could not open file for input.\n";
        	exit(EXIT_FAILURE);
    	}

    	GetStrs(fin, vistr);
    	cout << "\nHere are the strings read from the file:\n";
    	for_each(vistr.begin(), vistr.end(), ShowStr);
    	return 0;
}

void ShowStr(const string &s)
{
	cout << s << endl;
}
void GetStrs(ifstream &is, vector<string> &vs)
{
	size_t len;
	char *pt;

	while(is.read((char *)&len, sizeof(len)))
	{
		pt = new char[len];
		is.read(pt, len);
		vs.push_back(pt);
		delete [] pt;
	}
}