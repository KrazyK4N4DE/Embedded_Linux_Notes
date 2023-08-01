#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* tcpSocket;
    QString fileName;
    qint64 fileSize;
    QFile file;
    QTimer* timer;
};

#endif // WIDGET_H
