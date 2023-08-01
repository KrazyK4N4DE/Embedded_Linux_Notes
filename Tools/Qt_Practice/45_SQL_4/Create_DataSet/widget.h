#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

/*SQL接口层的头文件*/
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

/*用户接口层的头文件*/
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>

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
    QSqlTableModel* model;
};

#endif // WIDGET_H
