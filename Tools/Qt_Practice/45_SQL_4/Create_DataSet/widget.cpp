#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
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

//    /*插入数据*/
//    QString insert_sql = "insert into student values(?, ?, ?)";  // insert和into 之间加一个ignore可以防止重复添加
//    sql_query.prepare(insert_sql);
//    sql_query.addBindValue(1);  // 用addBindValue替代语句中的问号
//    sql_query.addBindValue("Rick");
//    sql_query.addBindValue(10);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else qDebug() << "Insert student NO.1";

//    sql_query.prepare(insert_sql);
//    sql_query.addBindValue(2);
//    sql_query.addBindValue("Jack");
//    sql_query.addBindValue(11);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else qDebug() << "Insert student NO.2";

//    /*查询*/
//    QString select_all_sql = "select * from student";
//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else
//    {
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug() << "Id: " << id << "   name: " << name << "    age: " << age;
//        }
//    }

//    /*更新表格*/
//    QString update_sql = "update student set name = :nm where id = :n";  // 这里nm和n为变量
//    sql_query.prepare(update_sql);
//    sql_query.bindValue(":nm", "Michael");
//    sql_query.bindValue(":n", "1");
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else qDebug() << "Updated";

//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else
//    {
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug() << "Id: " << id << "   name: " << name << "    age: " << age;
//        }
//    }

//    /*删除*/
//    QString delete_sql = "delete from student where id = ?";
//    sql_query.prepare(delete_sql);
//    sql_query.addBindValue(1);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else qDebug() << "Deleted";

//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else
//    {
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            int age = sql_query.value(2).toInt();
//            qDebug() << "Id: " << id << "   name: " << name << "    age: " << age;
//        }
//    }

//    /*清空数据库*/
//    QString clear_sql = "delete from student";
//    sql_query.prepare(clear_sql);
//    if(!sql_query.exec()) qDebug() << sql_query.lastError();
//    else qDebug() << "Table cleared";

    /*信息显示到界面上*/
    model = new QSqlTableModel(this);
    ui->tableView->setModel(model);
    model->setTable("student");
    model->select();  // 将信息显示出来

    model->setHeaderData(0, Qt::Horizontal, "学号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "年龄");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(!model->submitAll()) qDebug() << "Submit Failed!";
    else qDebug() << "Submit Successful!";
}

void Widget::on_pushButton_2_clicked()
{
    model->revertAll();
    model->submitAll();
}

void Widget::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text();
    QString nm = QString("name = '%1'").arg(name);
    model->setFilter(nm);  // 参数的格式为："name = 'xxx'"
    model->select();
}
