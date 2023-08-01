#include "dma.h"
#include <cstring>

ABC::ABC(const char *l, int r)
{
        label = new char[strlen(l) + 1];
        strcpy(label, l);
        rating = r;
}

ABC::ABC(const ABC &rs)
{
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
        rating = rs.rating;
}

ABC::~ABC()
{
        delete [] label;
}

ABC &ABC::operator=(const ABC &rs)
{
        if(this == &rs)
                return *this;
        delete [] label;
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
        rating = rs.rating;
        return *this;
}

ostream &operator<<(ostream &os, const ABC &rs)
{
        os << "Label: " << rs.label << endl;
        os << "Rating: " << rs.rating << endl;
        return os;
}

void ABC::View() const
{
        cout << "Label: " << label << endl;
        cout << "Rating: " << rating << endl;
}

baseDMA::baseDMA(const char *l, int r) : ABC(l, r)
{
}

baseDMA::baseDMA(const baseDMA &rs) : ABC(rs)
{
}

void baseDMA::View() const
{
        ABC::View();
}

//不使用动态内存分配的派生类方法
lacksDMA::lacksDMA(const char *c, const char *l, int r) : ABC(l, r)
{
        strncpy(color, c, COL_LEN - 1);
        color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const ABC &rs, const char *c) : ABC(rs)
{
        strncpy(color, c, COL_LEN - 1);
        color[COL_LEN - 1] = '\0';
}

ostream &operator<<(ostream &os, const lacksDMA &rs)
{
        os << (const ABC &)rs << endl; // 强制类型转换，爸爸可以引用儿子
        os << "Color: " << rs.color << endl;
        return os;
}

void lacksDMA::View() const
{
        ABC::View();
        cout << "Color: " << color << endl;
}

//使用动态内存分配的派生类方法
hasDMA::hasDMA(const char *s, const char *l, int r) : ABC(l, r)
{
        style = new char[strlen(s) + 1];
        strcpy(style, s);
}

hasDMA::hasDMA(const ABC &rs, const char *s) : ABC(rs)
{
        style = new char[strlen(s) + 1];
        strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : ABC(hs)
{
        style = new char[strlen(hs.style) + 1];
        strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
        delete [] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
        if (this == &hs)
                return *this;
        ABC::operator=(hs); // 调用父类的赋值运算符
        delete [] style;
        style = new char[strlen(hs.style) + 1];
        strcpy(style, hs.style);
        return *this;
}

ostream &operator<<(ostream &os, const hasDMA &hs)
{
        os << (const ABC &)hs << endl; // 强制类型转换，爸爸可以引用儿子
        os << "Style: " << hs.style << endl;
        return os;
}

void hasDMA::View() const
{
        ABC::View();
        cout << "Style: " << style << endl;
}