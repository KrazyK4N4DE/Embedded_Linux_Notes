#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*列出Qt支持的数据库*/
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach (QString driver, drivers)
//        qDebug() << driver;

    /*创建操作数据库的对象和数据库*/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dataset.db");
    if(!db.open()) qDebug() << "Error: Failed to connect to Database. " << db.lastError();
    else qDebug() << "Connect Database success!";

    /*创建表格Create table*/
    QSqlQuery sql_query;
//    QString create_sql = "create table student(id int, name varchar(30), age int)";
//    sql_query.prepare(create_sql);
//    if(!sql_query.exec()) qDebug() << "Error: Failed to create table. " << sql_query.lastError();
//    else qDebug() << "Table created!";

    /*插入数据*/
    QString insert_sql = "insert into student values(?, ?, ?)";  // insert和into 之间加一个ignore可以防止重复添加
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(1);  // 用addBindValue替代语句中的问号
    sql_query.addBindValue("Rick");
    sql_query.addBindValue(10);
    if(!sql_query.exec()) qDebug() << sql_query.lastError();
    else qDebug() << "Insert student NO.1";

    sql_query.prepare(insert_sql);
    sql_query.addBindValue(2);
    sql_query.addBindValue("Jack");
    sql_query.addBindValue(11);
    if(!sql_query.exec()) qDebug() << sql_query.lastError();
    else qDebug() << "Insert student NO.2";

    /*查询*/
    QString select_all_sql = "select * from student";
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec()) qDebug() << sql_query.lastError();
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString name = sql_query.value(1).toString();
            int age = sql_query.value(2).toInt();
            qDebug() << "Id: " << id << "   name: " << name << "    age: " << age;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
