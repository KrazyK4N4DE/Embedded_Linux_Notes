#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char *l, int r)
{
        label = new char[strlen(l) + 1];
        strcpy(label, l);
        rating = r;
}

baseDMA::baseDMA(const baseDMA &rs)
{
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
        rating = rs.rating;
}

baseDMA::~baseDMA()
{
        delete [] label;
}

baseDMA &baseDMA::operator=(const baseDMA &rs)
{
        if(this == &rs)
                return *this;
        delete [] label;
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
        rating = rs.rating;
        return *this;
}

ostream &operator<<(ostream &os, const baseDMA &rs)
{
        os << "Label: " << rs.label << endl;
        os << "Rating: " << rs.rating << endl;
        return os;
}

//不使用动态内存分配的派生类方法
lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r)
{
        strncpy(color, c, COL_LEN - 1);
        color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const baseDMA &rs, const char *c) : baseDMA(rs)
{
        strncpy(color, c, COL_LEN - 1);
        color[COL_LEN - 1] = '\0';
}

ostream &operator<<(ostream &os, const lacksDMA &rs)
{
        os << (const baseDMA &)rs << endl;  // 强制类型转换，爸爸可以引用儿子
        os << "Color: " << rs.color << endl;
        return os;
}

//使用动态内存分配的派生类方法
hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r)
{
        style = new char[strlen(s) + 1];
        strcpy(style, s);
}

hasDMA::hasDMA(const baseDMA &rs, const char *s) : baseDMA(rs)
{
        style = new char[strlen(s) + 1];
        strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs)
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
        baseDMA::operator=(hs); // 调用父类的赋值运算符
        delete [] style;
        style = new char[strlen(hs.style) + 1];
        strcpy(style, hs.style);
        return *this;
}

ostream &operator<<(ostream &os, const hasDMA &hs)
{
        os << (const baseDMA &)hs << endl; // 强制类型转换，爸爸可以引用儿子
        os << "Style: " << hs.style << endl;
        return os;
}