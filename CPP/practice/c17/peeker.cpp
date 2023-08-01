#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
        char ch;

        cout << "Enter something: \n";
        while(cin.get(ch))
        {
                if(ch != '#')
                        cout << ch;
                else
                {
                        cin.putback(ch);
                        break;
                }
        }
        cout << endl;

        if(!cin.eof())
        {
                cin.get(ch);
                cout << ch << " is next input character.\n";
        }
        else
        {
                cout << "End of file reached.\n";
                exit(0);
        }

        while(cin.peek() != '#')  //peek()只是查看下一个字符，不会从输入流中取出
        {
                cin.get(ch);
                cout << ch;
        }
        cout << endl;

        if(!cin.eof())
        {
                cin.get(ch);
                cout << ch << " is next input character.\n";
        }
        else
        {
                cout << "End of file reached.\n";
                exit(0);
        }

        return 0;       
}