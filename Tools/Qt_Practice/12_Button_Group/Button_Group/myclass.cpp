#include "myclass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

void MyClass::MySlot(void)
{
    qDebug() << "You failed the exam!";
}
