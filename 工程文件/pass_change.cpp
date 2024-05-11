#include "pass_change.h"
#include "ui_pass_change.h"
#include"p.h"
#include<QMessageBox>
Pass_Change::Pass_Change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pass_Change)
{
    ui->setupUi(this);
    setWindowTitle("修改密码");
}

Pass_Change::~Pass_Change()
{
    delete ui;
}



void Pass_Change::on_pushButton_2_clicked()
{
    QString Old=ui->lineEdit->text();
    QString New1=ui->lineEdit_2->text();
    QString New2=ui->lineEdit_3->text();
    if(New1.size()!=6)
    {
        ui->label_5->setText("新密码必须是6位数！！！");
        return;
    }

    if(New1!=New2)
    {
        ui->label_5->setText("两次密码不一致！！！");
        return;
    }
    if(Old!=Password())
    {
        ui->label_5->setText("旧密码错误！！！");
        return;
    }
    Password_Change(New1);
    reject();
    QMessageBox t(this);                                //整一个修改成功的提示
    t.setWindowTitle("修改密码");
    t.setText("修改成功！！");
    t.setIcon(QMessageBox::Information);//设置图标类型
    t.setStandardButtons(QMessageBox::Ok);
    if(t.exec()==QMessageBox::Ok)
    {
        t.close();
    }

}
