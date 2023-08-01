#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool same_after_reverse(const string &s);

int main()
{
        cout << "Enter a string: ";
        string str;
        cin >> str;

        if(same_after_reverse(str))
                cout << "The string is a palindrome." << endl;
        else
                cout << "The string is not a palindrome." << endl;

        return 0;
}

bool same_after_reverse(const string &s)
{
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        return tmp == s;
}