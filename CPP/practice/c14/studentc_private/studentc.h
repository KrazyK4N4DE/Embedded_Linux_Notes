#ifndef __STUDENTC_H__
#define __STUDENTC_H__

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

class Student : private string, private valarray<double>
{
private:
        typedef valarray<double> arrayDb;
        // string name;
        // arrayDb scores;
        ostream &arr_out(ostream &os) const;
public:
        Student() : string("Null Student"), arrayDb() {}
        //依旧是构造函数：valarray的几种传参法
        Student(const string &s, int n) : string(s), arrayDb(n) {}
        Student(const string &s, const arrayDb &a) : string(s), arrayDb(a) {}
        Student(const string &s, const double *pd, int n) : string(s), arrayDb(pd, n) {}
        // 取消隐式转换，因为类有两个变量，程序隐式转换后没啥意义
        explicit Student(const string &s) : string(s), arrayDb() {}
        explicit Student(int n) : string("Nully"), arrayDb(n) {}
        ~Student() {}
        double Average() const;
        const string &Name() const;
        //重载下标
        double &operator[](int n); // 返回double的引用，作左值，用于修改
        double operator[](int n) const; // 返回double，作右值，用于读取
        //重载输入
        friend istream &operator>>(istream &is, Student &stu);
        friend istream &getline(istream &is, Student &stu);
        //重载输出
        friend ostream &operator<<(ostream &os, const Student &stu);
};

#endif