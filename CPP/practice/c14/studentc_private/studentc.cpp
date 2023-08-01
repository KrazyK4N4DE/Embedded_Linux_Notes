/*
私有继承
*/
#include "studentc.h"

double Student::Average() const
{
        if (arrayDb::size() > 0)  //访问基类的方法
                return arrayDb::sum() / arrayDb::size();
        else
                cout << "Empty array!" << endl;
                return 0;
}

const string &Student::Name() const
{
        return (const string &) *this;  //访问基类对象
}

double &Student::operator[](int n)
{
        return arrayDb::operator[](n);
}

double Student::operator[](int n) const
{
        return arrayDb::operator[](n);
}

istream &operator>>(istream &is, Student &stu)
{
        is >> (string &)stu;
        return is;
}

istream &getline(istream &is, Student &stu)
{
        getline(is, (string &)stu);
        return is;
}

ostream &Student::arr_out(ostream &os) const
{
        int lim = arrayDb::size();  // 访问基类的友元函数
        int i = 0;

        if(lim > 0)
        {
                for(; i < lim; i++)
                {
                        os << arrayDb::operator[](i) << " ";
                        if(i % 5 == 4) // 每5个换行
                                os << endl;
                }
                if(i % 5 != 0) // 输出结束后如果光标没在新的一行，则换行
                        os << endl;
        }
        return os;
}

ostream &operator<<(ostream &os, const Student &stu)
{
        os << "Scores for " << (const string &)stu << ":\n";
        stu.arr_out(os);
}