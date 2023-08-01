#include <iostream>
#include <string>

using namespace std;

class Cpmv
{
public:
        struct Info
        {
                string qcode;
                string zcode;
        };

private:
        Info *pi;

public:
        Cpmv();
        Cpmv(string q, string z);
        Cpmv(const Cpmv &cp);
        Cpmv(Cpmv &&mv);
        ~Cpmv();
        Cpmv &operator=(const Cpmv &cp);
        Cpmv &operator=(Cpmv &&mv);
        Cpmv operator+(const Cpmv &obj) const;
        void Display() const;
};

Cpmv::Cpmv()
{
        pi = nullptr;
        cout << "Default construction.\n";
}

Cpmv::Cpmv(string q, string z)
{
        pi = new Info;
        pi->qcode = q;
        pi->zcode = z;
        cout << "Construction with args.\n";
}

Cpmv::Cpmv(const Cpmv &cp)
{
        pi = new Info;
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
        cout << "Copy construction.\n";
}

Cpmv::Cpmv(Cpmv &&mv)
{
        pi = mv.pi;
        mv.pi = nullptr;
        cout << "Move constuction.\n";
}

Cpmv::~Cpmv()
{
        delete pi; // 释放内存，可以对空指针调用delete
        cout << "Deconstruction.\n";
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
        cout << "Assignment function.\n";
        if (this == &cp)
                return *this;
        delete pi;
        pi = new Info;
        pi->qcode = cp.pi->qcode;
        pi->zcode = cp.pi->zcode;
        return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
        cout << "Move assignment function.\n";
        if (this == &mv)
                return *this;
        delete pi;
        pi = mv.pi;
        mv.pi = nullptr;
        return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
        cout << "Operator+.\n";
        return Cpmv((pi->qcode + obj.pi->qcode), (pi->zcode + obj.pi->zcode));
}

void Cpmv::Display() const
{
        cout << "Display Info:\n"
             << "-----------------------------\n";
        if (pi == nullptr)
                cout << "pi is null.\n";
        cout << "Address: " << pi << endl;
        cout << "qcode: " << pi->qcode << endl;
        cout << "zcode: " << pi->zcode << endl;
}

int main()
{
        Cpmv cp1("C", "C++");
        Cpmv cp2("computer", "language");

        Cpmv cp3(cp2);
        cp2 = cp1;
        Cpmv cp4(cp1 + cp2);

        return 0;
}