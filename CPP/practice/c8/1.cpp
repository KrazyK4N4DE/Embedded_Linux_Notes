#include<iostream>

using namespace std;

void showStr(const char *str, int n = 0);

int main()
{
        showStr("Hello");
        showStr("World");
        showStr("I Love U", 8);
        return 0;
}

void showStr(const char *str, int n)
{
        static int count = 0;
        count += 1;
        if(n == 0)
                cout << str << endl;
        else
        {
                for(int i = 0; i < count; i++)
                        cout << str << endl;
        }
}