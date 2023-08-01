#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
        string filename;

        cout << "Enter name of data file: ";
        cin >> filename;

        ifstream fin;
        fin.open(filename);
        cout << "here are the contents of " << filename << ": \n";

        char ch;
        int sum = 0;
        stringstream str;
        int n;

        while(fin.get(ch))
                str << ch;

        while(str >> n)
                sum += n;

        cout << "sum: " << sum << endl;
        fin.close();

        return 0;
}