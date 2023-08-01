#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemWatcher>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QFileSystemWatcher myWatcher;

private slots:
    void showMessage(const QString &path);
};

#endif // WIDGET_H
