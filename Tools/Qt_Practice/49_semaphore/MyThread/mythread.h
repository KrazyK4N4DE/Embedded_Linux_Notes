#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QSemaphore>

class Producer : public QThread
{
    Q_OBJECT
public:
    explicit Producer(){stopped = false;}
    void stop();
protected:
    void run();  // 线程从run函数开始运行；run函数是靠QThread类的start函数调用的
private:
    bool stopped;
};

class Consumer : public QThread
{
    Q_OBJECT
public:
    explicit Consumer(){stopped = false;}
    void stop();
protected:
    void run();  // 线程从run函数开始运行；run函数是靠QThread类的start函数调用的
private:
    bool stopped;
};

#endif // MYTHREAD_H
