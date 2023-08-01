#ifndef QMYCLASS_H
#define QMYCLASS_H

#include <QWidget>

class QMyClass : public QWidget
{
    Q_OBJECT
public:
    explicit QMyClass(QWidget *parent = 0);
    ~QMyClass();

signals:

public slots:
};

#endif // QMYCLASS_H
