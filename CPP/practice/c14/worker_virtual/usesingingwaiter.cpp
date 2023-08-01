#include <iostream>
#include <cstring>
#include "singingwaiter.h"

using namespace std;

const int SIZE = 3;

int main()
{
        Worker *lolas[SIZE];

        int i;
        char choice;
        for (i = 0; i < SIZE; i++)
        {
                cout << "Enter the employee category: \n"
                     << "w: waiter\ts: singer\tt: singing waiter\nq: quit"
                     << "\n-------------------------------------------------\n";
                cin >> choice;
                while (strchr("wstq", choice) == NULL)
                {
                        cout << "Enter w, s, t, or q: ";
                        cin >> choice;
                }
                if (choice == 'q')
                        break;
                switch (choice)
                {
                case 'w':
                        lolas[i] = new Waiter;
                        break;
                case 's':
                        lolas[i] = new Singer;
                        break;
                case 't':
                        lolas[i] = new SingingWaiter;
                        break;
                }
                while (cin.get() != '\n');
                lolas[i]->Set();
        }

        cout << "-------------------------------------------------\n"
             << "Here is your staff: \n";
        for (i = 0; i < SIZE; i++)
        {
                lolas[i]->Show();
                cout << endl;
        }

        for (i = 0; i < SIZE; i++)
                delete lolas[i];

        return 0;
}