#include<iostream>
#include<new>
#include<cstring>

using namespace std;

struct chaff
{
        char dross[20];
        int slag;
};

const int BUF = 512;
char buffer[BUF];

void showpd(const chaff &p);

int main()
{
        char dross[20];
        int slag;
        chaff *pd1 = new chaff[2];
        chaff *pd2 = new(buffer) chaff[2];

        for(int i = 0; i < 2; i++)
        {
                cout << "#" << i + 1 << ": " << endl;
                cout << "Enter dross: ";
                cin.getline(dross, 20);
                cout << "Enter slag: ";
                cin >> slag;
                cin.get();

                strcpy(pd1[i].dross, dross);
                strcpy(pd2[i].dross, dross);

                pd1[i].slag = slag;
                pd2[i].slag = slag;
        }
        cout << "******************************" << endl;
        for(int i = 0; i < 2; i++)
        {
                showpd(pd1[i]);
                showpd(pd2[i]);
        }
        delete [] pd1;

        return 0;
}

void showpd(const chaff &p)
{
        cout << "dross: " << p.dross << endl;
        cout << "slag: " << p.slag << endl;
}