#include "parking.h"
#include "ui_parking.h"

Parking::Parking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parking)
{
    ui->setupUi(this);
    setWindowTitle("刘英琦的停车场");
}

Parking::~Parking()
{
    delete ui;
}
void Parking::Add(Lot *p)
{
    N=p;
}

void Parking::on_pushButton_clicked()       //车子进入队伍
{
    InLine *p=new InLine();
    p->Add(N);                              //把停车场对象传进去
    p->show();
    if(p->exec()==QDialog::Accepted)        //处理返回键
    {
        p->close();
        show();
    }
}

void Parking::on_pushButton_2_clicked()
{
    OutPosi *p=new OutPosi();
    p->Add(N);
    p->show();
    close();
    if(p->exec()==QDialog::Accepted)
    {
        p->close();
        show();
    }
}

void Parking::on_pushButton_3_clicked()
{
    Check *p=new Check();
    p->Add(N);
    close();
    if(p->exec()==QDialog::Accepted)
    {
        p->close();
        show();
    }
}

void Parking::on_pushButton_4_clicked()
{
    All *p=new All();
    p->Add(N);
    close();
    if(p->exec()==QDialog::Accepted)
    {
        p->close();
        show();
    }
}

void Parking::on_pushButton_6_clicked()
{
    Fee f(this);
    f.Add(N);
    close();
    if(f.exec()==QDialog::Accepted)
    {
        show();
    }
}
