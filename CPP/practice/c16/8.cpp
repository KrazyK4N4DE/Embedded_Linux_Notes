#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void output(const string &s) {cout << s << " ";}

int main()
{
        set<string> Mat, Pat, Guest;
        string name;
        
        cout << "Mat's friends(\"quit\" to quit): \n";
        while(getline(cin, name) && name != "quit")
                Mat.insert(name);
        cout << "--------------------------------------------\n";

        cout << "Pat's friends(\"quit\" to quit): \n";
        while(getline(cin, name) && name != "quit")
                Pat.insert(name);
        cout << "--------------------------------------------\n";

        Guest.insert(Mat.begin(), Mat.end());
        Guest.insert(Pat.begin(), Pat.end());

        cout << "Mutual friends: \n";
        for_each(Guest.begin(), Guest.end(), output);
        cout << endl;

        return 0;
}