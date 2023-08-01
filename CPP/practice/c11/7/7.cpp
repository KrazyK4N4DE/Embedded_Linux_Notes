#include "complex0.h"

Complex::Complex()
{
        real = 0;
        imaginary = 0;
}
Complex::Complex(double r, double i)
{
        real = r;
        imaginary = i;
}

Complex Complex::operator+(const Complex &c) const
{
        return Complex(real + c.real, imaginary + c.imaginary);
}

Complex Complex::operator-(const Complex &c) const
{
        return Complex(real - c.real, imaginary - c.imaginary);
}

Complex Complex::operator*(const Complex &c) const
{
        return Complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}

Complex Complex::operator~() const
{
        return Complex(real, -imaginary);
}

Complex operator*(double n, const Complex &c)
{
        return Complex(n * c.real, n * c.imaginary);
}

istream &operator>>(istream &is, Complex &c)
{
        is >> c.real >> c.imaginary;
        return is;
}

ostream &operator<<(ostream &os, const Complex &c)
{
        os << "Real = " << c.real << "; Imaginary = " << c.imaginary << endl;
        return os;
}