#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*列出Qt支持的数据库*/
    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers)
        qDebug() << driver;

    /*创建操作数据库的对象*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataset.db");
    if(!db.open()) qDebug() << "Error: Failed to connect to Database. " << db.lastError();
    else qDebug() << "Connect Database success!";
}

Widget::~Widget()
{
    delete ui;
}
