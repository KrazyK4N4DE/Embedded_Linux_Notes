#include<iostream>
#include "mytime0.h"

using namespace std;

int main()
{
        Time coding = Time(2, 40);
        Time fixing(5, 55);

        cout << "coding time = ";
        coding.Show();
        cout << "fixing time = ";
        fixing.Show();

        Time total = coding.Sum(fixing);
        cout << "total time = ";
        total.Show();

        return 0;
}