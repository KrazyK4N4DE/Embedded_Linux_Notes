#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

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

    void on_pushButton_4_clicked();

    void getDuration(void);

    void sliderChanged(void);

private:
    Ui::Widget *ui;

    QMediaPlayer* player;
    QVideoWidget* videowidget;
    QString filename;
    qint64 pos;  // 播放位置
};

#endif // WIDGET_H
