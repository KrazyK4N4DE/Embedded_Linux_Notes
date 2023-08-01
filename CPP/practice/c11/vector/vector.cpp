#include "vector.h"
#include<cmath>

namespace VECTOR
{
        const double RAD_TO_DEG = 45.0 / atan(1.0); // 弧度角度转换系数

        void Vector::set_mag()
        {
                mag = sqrt(x * x + y * y);
        }
        void Vector::set_ang()
        {
                if(x == 0.0 && y == 0.0)
                        ang = 0.0;
                else
                        ang = atan2(y, x); //atan2(y, x)返回y/x的反正切值，范围为-pi到pi，单位为弧度
        }
        void Vector::set_x()
        {
                x = mag * cos(ang);
        }
        void Vector::set_y()
        {
                y = mag * sin(ang);
        }
        Vector::Vector()
        {
                x = y = mag = ang = 0.0;
                mode = RECT;
        }
        Vector::Vector(double n1, double n2, Mode form)
        {
                mode = form;
                if(form == RECT)
                {
                        x = n1;
                        y = n2;
                        set_mag();
                        set_ang();
                }
                else if(form == POL)
                {
                        mag = n1;
                        ang = n2 / RAD_TO_DEG;
                        set_x();
                        set_y();
                }
                else
                {
                        cout << "Error" << endl;
                        x = y = mag = ang = 0.0;
                        mode = RECT;
                }
        }
        void Vector::reset(double n1, double n2, Mode form)
        {
                mode = form;
                if(form == RECT)
                {
                        x = n1;
                        y = n2;
                        set_mag();
                        set_ang();
                }
                else if(form == POL)
                {
                        mag = n1;
                        ang = n2 / RAD_TO_DEG;
                        set_x();
                        set_y();
                }
                else
                {
                        cout << "Error" << endl;
                        x = y = mag = ang = 0.0;
                        mode = RECT;
                }
        }
        void Vector::polar_mode()
        {
                mode = POL;
        }
        void Vector::rect_mode()
        {
                mode = RECT;
        }
        Vector Vector::operator+(const Vector &v) const
        {
                return Vector(x + v.x, y + v.y);
        }
        Vector Vector::operator-(const Vector &v) const
        {
                return Vector(x - v.x, y - v.y);
        }
        Vector Vector::operator-() const
        {
                return Vector(-x, -y);
        }
        Vector operator*(double n, const Vector &v)
        {
                return Vector(n * v.x, n * v.y);
        }
        ostream &operator<<(ostream &os, const Vector &v)
        {
                if(v.mode == Vector::RECT) //POL要加限定
                        os << "x, y = " << v.x << ", " << v.y << endl;
                else if(v.mode == Vector::POL)
                        os << "mag, ang = " << v.mag << ", " << v.ang * RAD_TO_DEG << endl;
                else
                        os << "Error" << endl;

                return os;
        }
}