#include "myclass2.h"
#include <QDebug>

MyClass2::MyClass2(QObject *parent) : QObject(parent)
{

}

void MyClass2::MySlot(void)
{
    qDebug() << "Got Signal";
}

void MyClass2::Print(void)
{
    qDebug() << "Hello World";
}
