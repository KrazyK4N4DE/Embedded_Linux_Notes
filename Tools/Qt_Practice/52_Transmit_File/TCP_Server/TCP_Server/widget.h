#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>

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

private:
    Ui::Widget *ui;
    QTcpServer* tcpServer;
    QTcpSocket* clientConnection = nullptr;

    QString fileName;
    qint64 fileSize;
    qint64 receiveSize;
    bool headerInfo = true;  // 用bool判断发的是文件头还是内容
    QFile file;
};

#endif // WIDGET_H
