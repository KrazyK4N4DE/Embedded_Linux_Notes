#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Gender" << "Age");
    ui->tableWidget->setRowCount(3);
    // ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Rick"));
    QStringList NameList;
    NameList << "Rick" << "Jack" << "Michael";
    QStringList GenderList;
    GenderList << "Female" << "Male" << "Male";
    for(int row = 0; row < 3; ++row)
    {
        int col = 0;
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(NameList[row]));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(GenderList[row]));
        ui->tableWidget->setItem(row, col, new QTableWidgetItem(QString::number(20)));
    }
}

Widget::~Widget()
{
    delete ui;
}
