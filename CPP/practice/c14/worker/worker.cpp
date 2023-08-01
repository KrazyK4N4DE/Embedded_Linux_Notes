#include "worker.h"

void Worker::Set()
{
        cout << "Enter worker's name: ";
        getline(cin, name);
        cout << "Enter worker's ID: ";
        cin >> id;
        while(cin.get() != '\n');
}

void Worker::Show() const
{
        cout << "Name: " << name << "\nID: " << id << endl;
}

void Waiter::Set()
{
        Worker::Set();
        cout << "Enter waiter's panache rating: ";
        cin >> panache;
        while(cin.get() != '\n');
}

void Waiter::Show() const
{
        Worker::Show();
        cout << "Panache rating: " << panache << endl;
}

const char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
        Worker::Set();

        int i;
        for(i = 0; i < Vtypes; i++)
        {
                cout << i << ": " << pv[i] << " ";
                if(i % 4 == 3)
                        cout << endl;
        }
        if(i % 4 != 0)
                cout << endl;

        cout << "Enter number for singer's vocal range(0 ~ Vtypes): \n";
        cin >> voice;
        while(cin.get() != '\n');
}

void Singer::Show() const
{
        Worker::Show();
        cout << "Vocal range: " << pv[voice] << endl;
}