#ifndef __SINGINGWAITER_H__
#define __SINGINGWAITER_H__

#include <iostream>
#include <string>

using namespace std;

class Worker
{
private:
        string name;
        long id;
protected:
        virtual void Data() const;
        virtual void Get();
public:
        Worker() : name("None None"), id(0l) {}
        Worker(const string &s, long n) : name(s), id(n) {}
        virtual ~Worker() {}
        virtual void Set() = 0;
        virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
        int panache;  // 服务态度
protected:
        virtual void Data() const;
        virtual void Get();
public:
        Waiter() : Worker(), panache(0) {}
        Waiter(const string &s, long n, int p = 0) : Worker(s, n), panache(p) {}
        Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
        virtual void Set();
        virtual void Show() const;
};

class Singer : virtual public Worker
{
protected:
        virtual void Data() const;
        virtual void Get();
        enum {other, alto, contralto, soprano, bass, baritone, tenor};  // 声音类型
        enum {Vtypes = 7};  // 7种类型
private:
        static const char *pv[Vtypes]; // 在类声明中声明，在包含类方法的文件中初始化。因为头文件可能放到好几个文件中，所以不能包含初始化
        int voice;
public:
        Singer() : Worker(), voice(other) {}
        Singer(const string &s, long n, int v = other) : Worker(s, n), voice(v) {}
        Singer(const Worker &wk, int v = other) : Worker(wk), voice(v) {}
        virtual void Set();
        virtual void Show() const;
};

class SingingWaiter : public Waiter, public Singer
{
protected:
        virtual void Data() const {};
        virtual void Get() {};
public:
        SingingWaiter() {}
        SingingWaiter(const string &s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
        SingingWaiter(const Worker &wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
        virtual void Set();
        virtual void Show() const;
};

#endif