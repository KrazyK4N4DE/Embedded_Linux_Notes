#include <iostream>

using namespace std;

const double *f1(const double ar[], int n);
const double *f2(const double[], int);
const double *f3(const double *, int n);

int main()
{
        double av[3] = {1112.3, 1542.6, 2227.9};

        //函数指针
        const double *(*p1)(const double[], int) = f1;
        auto p2 = f2; // C++11 automatic type deduction
        cout << "Using pointers to functions:\nAddress Value\n"
             << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl
             << p2(av, 3) << ": " << *p2(av, 3) << endl;

        //指向函数的指针数组
        const double *(*pa[3])(const double *, int) = {f1, f2, f3};
        auto pb = pa; // C++11 automatic type deduction
        // const double *(**pb)(const double *, int) = pa;
        cout << "\nUsing an array of pointers to functions:\nAddress Value\n";
        for (int i = 0; i < 3; i++)
                cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;

        //指向指针的指针
        cout << "\nUsing pointers to pointers to functions:\nAddress Value\n";
        for (int i = 0; i < 3; i++)
                cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

        //指向函数的指针的指针
        cout << "\nUsing pointers to an array of pointers:\nAddress Value\n";
        auto pc = &pa; // C++11 automatic type deduction
        // const double *(*(*pc)[3])(const double *, int) = &pa;
        cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
        const double *(*(*pd)[3])(const double *, int) = &pa;
        const double *pdb = (*pd)[1](av, 3);
        cout << pdb << ": " << *pdb << endl;
        //另一种写法
        cout << (*(*pd)[2])(av,3) << ": " << *((*pd)[2])(av,3) << endl;


        return 0;
}

//返回数组第一个元素的地址
const double *f1(const double ar[], int n)
{
        return ar;
}

//返回数组第二个元素的地址
const double *f2(const double ar[], int n)
{
        return ar + 1;
}

//返回数组第三个元素的地址
const double *f3(const double ar[], int n)
{
        return ar + 2;
}
