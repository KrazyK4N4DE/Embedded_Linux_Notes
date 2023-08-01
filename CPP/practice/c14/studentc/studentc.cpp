#include "studentc.h"

double Student::Average() const
{
        if (scores.size() > 0)
                return scores.sum() / scores.size();
        else
                cout << "Empty array!" << endl;
                return 0;
}

const string &Student::Name() const
{
        return name;
}

double &Student::operator[](int n)
{
        return scores[n];
}

double Student::operator[](int n) const
{
        return scores[n];
}

istream &operator>>(istream &is, Student &stu)
{
        is >> stu.name;
        return is;
}

istream &getline(istream &is, Student &stu)
{
        getline(is, stu.name);
        return is;
}

ostream &operator<<(ostream &os, const Student &stu)
{
        int lim = stu.scores.size();
        int i = 0;

        os << "Scores for " << stu.name << ":\n";

        if(lim > 0)
        {
                for(; i < lim; i++)
                {
                        os << stu.scores[i] << " ";
                        if(i % 5 == 4) // 每5个换行
                                os << endl;
                }
                if(i % 5 != 0) // 输出结束后如果光标没在新的一行，则换行
                        os << endl;
        }
        return os;
}