#include <iostream>
#include <cctype>
#include "5_stack.h"

using namespace std;

int main()
{
        char ch;
        Item po;
        Stack st;
        double sum = 0.0;

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
                                cout << "Enter a customer's fullname to add: ";
                                cin.getline(po.fullname, 35);
                                cout << "Enter a customer's payment to add: ";
                                cin >> po.payment;
                                cin.get();
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
                                sum += po.payment;
                                cout << "Item " << po.fullname << " popped." << endl;
                                cout << "Item " << po.payment << " popped." << endl;
                                cout << "\nSum of payment: " << sum << endl;
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