#include <iostream>

using namespace std;

const int SIZE = 10;

void strcount(const char *str);

int main()
{
        char input[SIZE];
        char next;

        cout << "Enter a line of text:" << endl;
        cin.get(input, SIZE);
        while(cin)
        {
                cin.get(next);
                while(next != '\n')
                        cin.get(next);
                strcount(input);
                cout << "Enter next line (empty line to quit):" << endl;
                cin.get(input, SIZE);
        }

        return 0;
}

void strcount(const char *str)
{
        static int total = 0;
        int count = 0;
        while(*str++)
                count++;
        total += count;
        cout << count << " characters\n";
        cout << total << " characters total\n";     
}