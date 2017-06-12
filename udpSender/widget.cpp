#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    sender = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked() // 开始广播
{
    QByteArray datagram = "hello world!";
    QHostAddress adr =QHostAddress("192.168.0.139");
    sender->writeDatagram(datagram.data(),datagram.size(),
                         adr,45454);
    qDebug("once");
}
