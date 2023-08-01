#ifndef MYCLASS1_H
#define MYCLASS1_H

#include <QObject>

class MyClass1 : public QObject
{
    Q_OBJECT
public:
    explicit MyClass1(QObject *parent = 0);

signals:
    void MySignal(void);

public slots:
};

#endif // MYCLASS1_H
