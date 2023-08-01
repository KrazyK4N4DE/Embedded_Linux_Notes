/*
使用不同特征标，可以实现left()的函数重载
*/
#include<iostream>

using namespace std;

char *left(const char *str, int n = 1);
unsigned long left(unsigned long num, unsigned ct = 1);

int main()
{
        //测试值
        char *trip = "Hawaii";
        unsigned long n = 12345678;

        for(int i = 1; i < 10; i++)
        {
                cout << left(n, i) << endl;
                char *tmp = left(trip, i);
                cout << tmp << endl;
        }

        return 0;
}

//取一个字符串的前n个
char *left(const char *str, int n)
{
        if (n < 0)
                n = 0;

        int m = 0;
        while (m < n && str[m])
                m++;

        char *p = new char[m + 1];

        int i;
        for (i = 0; i < m; i++)
                p[i] = str[i];

        p[i] = '\0';

        return p;
}

//取一个数字的前n位
unsigned long left(unsigned long num, unsigned ct)
{
        unsigned long n = num;
        unsigned digits = 1;

        if(ct == 0 || num == 0)
                return 0;
        
        while(n /= 10)
                digits++; //计算数字有多少位
        
        if(digits > ct)
        {
                ct = digits - ct;
                while(ct--)
                        num /= 10;
                return num;
        }
        else
                return num;
}