#include "mythread.h"
#include <QDebug>

const int size = 10;
unsigned int buffer[size];  // 生产者生产出来的产品放到这里，消费者购买
QSemaphore usedSem(0);  // 信号量
QSemaphore unusedSem(size);  // 信号量

/*生产者*/
void Producer::run()
{
    int i = 0;
    while(!stopped)
    {
        unusedSem.acquire();  // 调用一次acquire，unusedSem的量就-1
        buffer[i] = i;
        msleep(1000);
        qDebug() << "Write to the shared memory.";
        usedSem.release();  // usedSem的量+1
        ++i;
        if(i == size) i = 0;
    }
    stopped = false;
}

void Producer::stop()
{
    stopped = true;
}

/*消费者*/
void Consumer::run()
{
    int i = 1;
    while(!stopped)
    {
        usedSem.acquire();
        qDebug() << buffer[i];
        unusedSem.release();
        ++i;
        if(i == size) i = 0;
    }
    stopped = false;
}

void Consumer::stop()
{
    stopped = true;
}
