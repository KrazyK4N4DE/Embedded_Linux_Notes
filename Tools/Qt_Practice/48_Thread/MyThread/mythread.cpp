#include "mythread.h"
#include <QDebug>

void MyThread::run()
{
    int i = 0;
    while(!stopped)
    {
        qDebug() << "MyThread_1: " << i;
        msleep(1000);
        i += 2;
    }
    stopped = false;
}

void MyThread::stop()
{
    stopped = true;
}

void MyThread_2::run()
{
    int i = 1;
    while(!stopped)
    {
        qDebug() << "MyThread_2: " << i;
        msleep(1000);
        i += 2;
    }
    stopped = false;
}

void MyThread_2::stop()
{
    stopped = true;
}
