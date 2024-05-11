#include "inline.h"
#include "ui_inline.h"
#include"QDebug"
InLine::InLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InLine)
{
    ui->setupUi(this);
    setWindowTitle("进车");
}

InLine::~InLine()
{
    delete ui;
}
void InLine::Add(Lot *p)
{
    N=p;
}

void InLine::on_pushButton_clicked()            //确定选项
{
    if(N->L->LineSize()==N->Ln)             //当停车队伍已满时，进车失败
    {
        accept();
        QMessageBox t(this);                                //整一个进车失败的提示
        t.setWindowTitle("进车失败");
        t.setText("当前队伍已满，请后再来！");
        t.setIcon(QMessageBox::Information);//设置图标类型
        t.setStandardButtons(QMessageBox::Ok);
        if(t.exec()==QMessageBox::Ok)
        {
            t.close();
        }
    }
    else
    {
        QString Num=ui->lineEdit->text();               //接受输入框内的车牌号和品牌
        QString Band=ui->comboBox->currentText();
        N->L->AddLine(Num,Band);
        accept();
        QMessageBox t(this);                                //整一个进车成功的提示
        t.setWindowTitle("进车成功");
        QString str="车牌号为"+Num+"的"+Band+"进车成功！";
        t.setText(str);
        t.setIcon(QMessageBox::Information);                //设置图标类型
        t.setStandardButtons(QMessageBox::Ok);
        if(t.exec()==QMessageBox::Ok)
        {
            t.close();
        }
    }
    if(N->P->ParkSize()!=N->Pn)                     //停车场有空位时，打开进入车位的页面
    {
        InPosi* t=new InPosi();
        t->Add(N);                                  //老样子，传递对象
        t->show();
        if(t->exec()==QDialog::Accepted)
        {
            t->close();
        }
    }

}
