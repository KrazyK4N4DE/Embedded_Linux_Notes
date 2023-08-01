#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = 0);
    ~widget();
};

#endif // WIDGET_H
