#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList() << "Name" << "Address");

    QTreeWidgetItem* treeitem1 = new QTreeWidgetItem(QStringList() << "Bookmarks Toolbar");
    treeitem1->setIcon(0, QIcon(":/Images/Images/folder.png"));
    ui->treeWidget->addTopLevelItem(treeitem1);
    QTreeWidgetItem* treeitem2 = new QTreeWidgetItem(QStringList("Bookmarks Menu"));
    treeitem2->setIcon(0, QIcon(":/Images/Images/folder.png"));
    ui->treeWidget->addTopLevelItem(treeitem2);

    QTreeWidgetItem* childitem1 = new QTreeWidgetItem(QStringList("QWidget") << "Page 10");
    treeitem1->addChild(childitem1);
    QTreeWidgetItem* childitem2 = new QTreeWidgetItem(QStringList("QMainWindow") << "Page 21");
    treeitem1->addChild(childitem2);

    QTreeWidgetItem* childitem3 = new QTreeWidgetItem(QStringList("QPushButton") << "Page 26");
    treeitem2->addChild(childitem3);
    QTreeWidgetItem* childitem4 = new QTreeWidgetItem(QStringList("QLabel") << "Page 40");
    treeitem2->addChild(childitem4);
}

Widget::~Widget()
{
    delete ui;
}
