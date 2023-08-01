#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <string>

using namespace std;

class Worker
{
private:
        string name;
        long id;
public:
        Worker() : name("None None"), id(0l) {}
        Worker(const string &s, long n) : name(s), id(n) {}
        virtual ~Worker() {}
        virtual void Set();
        virtual void Show() const;
};

class Waiter : public Worker
{
private:
        int panache;  // 服务态度
public:
        Waiter() : Worker(), panache(0) {}
        Waiter(const string &s, long n, int p = 0) : Worker(s, n), panache(p) {}
        Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
        virtual void Set();
        virtual void Show() const;
};

class Singer : public Worker
{
protected:
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

#endif