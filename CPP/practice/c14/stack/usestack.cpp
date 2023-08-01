#include <iostream>
#include <cctype>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
        char ch;
        string po;
        Stack<string> st;

        cout << "**************************************\n"
             << "Please enter A to push in stack,\n"
             << "P to pop from stack, or Q to quit.\n"
             << "**************************************\n";

        while ((cin >> ch) && (toupper(ch) != 'Q'))
        {
                while (cin.get() != '\n')
                        continue;
                switch (ch)
                {
                case 'A':
                case 'a':
                        if (st.isfull())
                                cout << "Pity! Stack fulled." << endl;
                        else
                        {
                                cout << "Enter an item to add: ";
                                cin >> po;
                                st.push(po);
                                cout << "--------------------------------------\n";
                        }
                        break;
                case 'P':
                case 'p':
                        if (st.isempty())
                                cout << "Pity! Stack empty." << endl;
                        else
                        {
                                st.pop(po);
                                cout << "Item " << po << " popped." << endl;
                                cout << "--------------------------------------\n";
                        }
                        break;
                }
                cout << "Please enter A to push in stack,\n"
                     << "P to pop from stack, or Q to quit.\n"
                     << "**************************************\n";
        }
        return 0;
}