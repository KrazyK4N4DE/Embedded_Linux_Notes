#ifndef MYCUSTOMCONTROLLER_H
#define MYCUSTOMCONTROLLER_H

#include <QWidget>

namespace Ui {
class MyCustomController;
}

class MyCustomController : public QWidget
{
    Q_OBJECT

public:
    explicit MyCustomController(QWidget *parent = 0);
    ~MyCustomController();

    int get_Value(void);

private:
    Ui::MyCustomController *ui;
};

#endif // MYCUSTOMCONTROLLER_H
