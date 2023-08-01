#ifndef __VECTOR_H__
#define __VECTOR_H__

#include<iostream>

using namespace std;

namespace VECTOR
{
        class Vector
        {
        public:
                enum Mode {RECT, POL}; //直角坐标和极坐标
        private:
                double x;
                double y;
                double mag;
                double ang;
                Mode mode;
                void set_mag();
                void set_ang();
                void set_x();
                void set_y();
        public:
                Vector();
                Vector(double n1, double n2, Mode form = RECT);
                void reset(double n1, double n2, Mode form = RECT);
                double xval() const {return x;}
                double yval() const {return y;}
                double magval() const {return mag;}
                double angval() const {return ang;}
                void polar_mode();
                void rect_mode();

                Vector operator+(const Vector &v) const;
                Vector operator-(const Vector &v) const;
                //不接受参数，表示将坐标值取反
                Vector operator-() const; 
                //Vector operator*(double n) const;
                friend Vector operator*(double n, const Vector &v);
                friend ostream &operator<<(ostream &os, const Vector &v);
        };
}

#endif