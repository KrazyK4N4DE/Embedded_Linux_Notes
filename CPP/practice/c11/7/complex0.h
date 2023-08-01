/*
* @brief  复数的类，包含复数的加减乘除、以及共轭
*/
#ifndef __COMPLEX0_H__
#define __COMPLEX0_H__

#include <iostream>

using namespace std;

class Complex
{
private:
        double real;
        double imaginary;
public:
        Complex();
        Complex(double r, double i);
        Complex operator+(const Complex &c) const;
        Complex operator-(const Complex &c) const;
        Complex operator*(const Complex &c) const;
        Complex operator~() const;
        friend Complex operator*(double n, const Complex &c);
        //由于是写入，这里Complex引用不能加const
        friend istream &operator>>(istream &is, Complex &c);
        friend ostream &operator<<(ostream &os, const Complex &c);
};

#endif