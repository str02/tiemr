#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    enmucomport();
}

Widget::~Widget()
{

    delete ui;
}

void Widget::enmucomport()
{

    QStringList serialportinfolist;
    re.clear();
    //QSerialPortInfo 所有的端口信息
    //QSerialPortInfo::availablePorts 可以用的端口 就是存在的端口
    foreach (const QSerialPortInfo &info , QSerialPortInfo::availablePorts())
    {
     qDebug()<< info.portName() +"       "+ info.manufacturer();
     serialportinfolist.append(info.portName() +"       "+ info.manufacturer());
     re.append(info.portName());
    }
    ui->comboBox->clear();
    ui->comboBox->insertItems(0,serialportinfolist);
}
