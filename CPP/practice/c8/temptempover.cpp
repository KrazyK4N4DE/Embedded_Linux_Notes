/*
函数模板的完全匹配与最佳匹配
*/
#include<iostream>

using namespace std;

struct money
{
        char name[20];
        double salary;
};


template <typename T>
void ShowArr(T arr[], int n);
template <typename T>
void ShowArr(T *arr[], int n);

int main()
{
        int things[6] = {13, 31, 103, 301, 310, 130};
        ShowArr(things, 6);

        money mr[3] = 
        {
                {"Rick", 2400.00},
                {"Jack", 1300.0},
                {"Rose", 1800}
        };
        double *pd[3];
        for(int i = 0; i < 3; i++)
                pd[i] = &mr[i].salary;
        ShowArr(pd, 3);

        return 0;
}

//函数模板，与things匹配；与pd完全匹配，但是输出的是地址值，不符合需求，所以不是最佳匹配
template <typename T>
void ShowArr(T arr[], int n)
{
        cout << "Template A:\n";
        for(int i = 0; i < n; i++)
                cout << arr[i] << ' ';
        cout << endl;
}

//重载后的函数模板，形参是指针，是pd的最佳匹配
template <typename T>
void ShowArr(T *arr[], int n)
{
        cout << "Template B:\n";
        for(int i = 0; i < n; i++)
                cout << *arr[i] << ' ';
        cout << endl;
}