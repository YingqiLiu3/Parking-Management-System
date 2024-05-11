#include "fee.h"
#include "ui_fee.h"
#include<QMessageBox>
Fee::Fee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fee)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox_2->setMinimum(1);
}

Fee::~Fee()
{
    delete ui;
}
void Fee::Add(Lot *p)
{
    N=p;
}

void Fee::on_pushButton_clicked()
{
    N->T=ui->spinBox->value();
    N->M=ui->spinBox_2->value();
    accept();
    QMessageBox t(this);                                //整一个修改成功的提示
    t.setWindowTitle("收费设置");
    t.setText("修改成功！");
    t.setIcon(QMessageBox::Information);//设置图标类型
    t.setStandardButtons(QMessageBox::Ok);
    if(t.exec()==QMessageBox::Ok)
    {
        t.close();
    }
}
