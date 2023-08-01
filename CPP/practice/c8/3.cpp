#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void ToUpper(string &str);

int main()
{
        string str;
        cout << "Enter a string (q to quit): ";
        getline(cin, str);
        while(str != "q")
        {
                ToUpper(str);
                cout << str << endl;
                cout << "Next string (q to quit): ";
                getline(cin, str);
        }
        return 0;
}

void ToUpper(string &str)
{
        for(int i = 0; i < str.size(); i++)
                str[i] = toupper(str[i]);
}