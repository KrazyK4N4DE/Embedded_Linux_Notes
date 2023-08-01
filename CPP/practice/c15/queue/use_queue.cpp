#include <iostream>
#include "queue.h"
#include <string>

using namespace std;

int main()
{
        Queue<string> cs(5);
        string tmp;

        while(!cs.isfull())
        {
                cout << "Enter client's name: \n";
                getline(cin, tmp);
                cs.enqueue(tmp);
        }

        cout << "The queue is full. Processing begins.\n";

        while(!cs.isempty())
        {
                cs.dequeue(tmp);
                cout << "Now processing: " << tmp << endl;
        }

        return 0;
}       