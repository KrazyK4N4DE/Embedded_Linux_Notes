#include "singingwaiter.h"

void Worker::Get()
{
        cout << "Enter worker's name: ";
        getline(cin, name);
        cout << "Enter worker's ID: ";
        cin >> id;
        while(cin.get() != '\n');
}

void Worker::Data() const
{
        cout << "Name: " << name << "\nID: " << id << endl;
}

// Waiter类
void Waiter::Get()
{
        cout << "Enter waiter's panache rating: ";
        cin >> panache;
        while(cin.get() != '\n');
}

void Waiter::Data() const
{
        cout << "Panache rating: " << panache << endl;
}

void Waiter::Set()
{
        Worker::Get();
        Get();
}

void Waiter::Show() const
{
        Worker::Data();
        Data();
}

// Singer类
const char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Get()
{
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

void Singer::Data() const
{
        cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Set()
{
        Worker::Get();
        Get();
}

void Singer::Show() const
{
        Worker::Data();
        Data();
}

// SingingWaiter类
void SingingWaiter::Set()
{
        Worker::Get();
        Waiter::Get();
        Singer::Get();
}

void SingingWaiter::Show() const
{
        Worker::Data();
        Waiter::Data();
        Singer::Data();
}