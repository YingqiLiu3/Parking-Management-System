#include "check.h"
#include "ui_check.h"
#include<QDebug>
Check::Check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);
    setWindowTitle("查询信息");
}

Check::~Check()
{
    delete ui;
}
void Check::Add(Lot *p)
{
    N=p;
}

void Check::on_pushButton_clicked()
{
    QString Num=ui->lineEdit->text();
    int i=N->P->CheckCar1(Num);
    if(!i)  //假如查找不到车牌
    {
        ui->label_2->setText("             查无此车");
    }
    else
    {
        Car*NowCar=N->P->CheckCar2(i);
        QString str="停车位："+QString::number(i)+"号 "
                +"车牌号："+NowCar->Num
                +" 品牌："+NowCar->Band+
                +" 入场时间："+NowCar->InTime.ShowTime();
        ui->label_2->setText(str);
    }
}
