#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
int reduce(T ar[], int n);

int main()
{
        long arr[5] = {200, 100, 300, 100, 200};
        int size = reduce(arr, 5);

        for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
        cout << endl;

        string str[5] = {"hello", "world", "good", "morning", "world"};
        size = reduce(str, 5);

        for (int i = 0; i < size; i++)
                cout << str[i] << " ";
        cout << endl;

        return 0;
}

template <class T>
int reduce(T ar[], int n)
{
        // 先放入容器中
        list<T> ls;
        for (int i = 0; i < n; i++)
                ls.push_back(ar[i]);
        ls.sort();
        ls.unique();
        // 再放回数组中
        auto pt = ls.begin();
        for (int i = 0; i < ls.size(); i++, pt++)
                ar[i] = *pt;

        return ls.size();
}