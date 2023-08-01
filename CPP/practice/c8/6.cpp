#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T maxn(T t[], int);
template <> char *maxn<char *>(char *str[], int n);

int main()
{
        int a[6] = {1, 2, 3, 4, 5, 6};
        double b[4] = {1.1, 2.2, 3.3, 4.4};
        //一般来说不能将字符串常量赋给char *，但是这里是模板特化，所以可以
        //解决方法：改成string类型
        char *str[5] = {"Hello", "world.", "This", "is", "a!"};
        

        cout << maxn(a, 6) << endl;
        cout << maxn(b, 4) << endl;
        cout << maxn(str, 5) << endl;

        return 0;
}

template <typename T>
T maxn(T t[], int n)
{
        T max = t[0];
        for (int i = 0; i < n; i++)
        {
                if(t[i] > max)
                        max = t[i];
        }
        return max;
}

template <> char *maxn<char *>(char *str[], int n)
{
        char *max = str[0];
        for(int i = 0; i < n; i++)
        {
                if(strlen(str[i]) > strlen(max))
                        max = str[i];
        }
        return max;
}