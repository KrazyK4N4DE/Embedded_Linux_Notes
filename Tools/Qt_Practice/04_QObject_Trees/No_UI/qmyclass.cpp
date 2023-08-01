#include "qmyclass.h"
#include <QDebug>

QMyClass::QMyClass(QWidget *parent) : QWidget(parent)
{

}

QMyClass::~QMyClass()
{
    qDebug() << "Delete MyClass.";
}
