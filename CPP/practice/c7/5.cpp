#include<iostream>

using namespace std;

long long factorial(int n);

int main()
{
        int num;
        long long result = 1;
        cout << "Enter a number for factorial: ";
        while(cin >> num)
        {
                result = factorial(num);
                cout << num << "!= " << result << endl;
                cout << "Enter a number for factorial: ";
        }

        return 0;
}

//用递归实现
long long factorial(int n)
{
        if(n == 0)
                return 1;
        else    
                return n * factorial(n - 1);
}