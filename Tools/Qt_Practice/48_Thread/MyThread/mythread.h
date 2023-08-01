#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(){stopped = false;}
    void stop();
protected:
    void run();  // 线程从run函数开始运行；run函数是靠QThread类的start函数调用的，所以放在protected中
private:
    bool stopped;
};

class MyThread_2 : public QThread
{
    Q_OBJECT
public:
    explicit MyThread_2(){stopped = false;}
    void stop();
protected:
    void run();  // 线程从run函数开始运行；run函数是靠QThread类的start函数调用的
private:
    bool stopped;
};

#endif // MYTHREAD_H
