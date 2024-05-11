#include "all.h"
#include "ui_all.h"

All::All(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::All)
{
    ui->setupUi(this);
    setWindowTitle("查看停车场信息");
    resize(500,500);
}
void All::Add(Lot *p)
{
    N=p;
    QString str=
            "车道："+QString::number(N->L->LineSize())+"辆  "
            +"车场："+QString::number(N->P->ParkSize())+"辆  "
            +"剩余车位："+QString::number(N->Pn-N->P->ParkSize())+"个"
            +'\n'
            +"收费设置：  "+QString::number(N->M)+"元/"+QString::number(N->T)
            +"分钟";
    ui->label->setText(str);
    ui->label_2->setText(N->P->ShowAll());
}
All::~All()
{
    delete ui;
}
