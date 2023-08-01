#ifndef __DMA_H__
#define __DMA_H__

#include <iostream>

using namespace std;

// 基类使用动态内存分配
class baseDMA
{
private:
        char *label;
        int rating;
public:
        baseDMA(const char *l = "null", int r = 0);
        baseDMA(const baseDMA &rs); // 拷贝构造函数，初始化对象时使用
        virtual ~baseDMA();
        baseDMA &operator=(const baseDMA &rs); // 赋值运算符，一个对象赋值给另一个对象时使用
        friend ostream &operator<<(ostream &os, const baseDMA &rs);
};

// 派生类不使用动态内存分配
class lacksDMA : public baseDMA
{
private:
        enum{COL_LEN = 40};
        char color[COL_LEN];
public:
        lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
        lacksDMA(const baseDMA &rs, const char *c = "blank");
        //派生类没有使用动态内存分配，所以不需要析构函数、拷贝构造函数、赋值运算符重载
        friend ostream &operator<<(ostream &os, const lacksDMA &rs);
};

// 派生类使用动态内存分配
class hasDMA : public baseDMA
{
private:
        char *style;
public:
        hasDMA(const char *s = "none", const char *l = "null", int r = 0);
        hasDMA(const baseDMA &rs, const char *s);
        //没有复制构造函数的话，指针赋给指针为浅拷贝，需要深拷贝，动态内存分配
        hasDMA(const hasDMA &hs);
        ~hasDMA();
        hasDMA &operator=(const hasDMA &hs);
        friend ostream &operator<<(ostream &os, const hasDMA &rs);
};

#endif