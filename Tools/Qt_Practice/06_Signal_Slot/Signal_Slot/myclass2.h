#ifndef MYCLASS2_H
#define MYCLASS2_H

#include <QObject>

class MyClass2 : public QObject
{
    Q_OBJECT
public:
    explicit MyClass2(QObject *parent = 0);

signals:

public slots:
    void MySlot(void);
    void Print(void);
};

#endif // MYCLASS2_H
