#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QtSerialPort>
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
    void TimerEvent(void);  // 自定义槽，用于检查更新可用的串口
    void serialPort_readyRead(void);

    void on_pushButton_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QTimer* timer;
    QStringList portStringList;
    QSerialPort* serial;
    QString receiveText;
    QString sendText;
    long receivceByteNum, sendByteNum;
};

#endif // WIDGET_H
