#include "outposi.h"
#include "ui_outposi.h"

OutPosi::OutPosi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutPosi)
{
    ui->setupUi(this);
    setWindowTitle("出车");
    ui->spinBox_4->setMinimum(0);      //设置一下输入框的取值范围
    ui->spinBox_4->setMaximum(23);
    ui->spinBox_3->setMinimum(0);
    ui->spinBox_3->setMaximum(59);
}

void OutPosi::Add(Lot *p)
{
    N=p;
}

OutPosi::~OutPosi()
{
    delete ui;
}

void OutPosi::on_pushButton_clicked()
{
    QString Num=ui->lineEdit->text();
    int i=N->P->CheckCar1(Num);
    if(!i)
    {
        ui->label_3->setText("查无此车！！");
    }
    else
    {
        accept();
        int hour=ui->spinBox_4->value();
        int min=ui->spinBox_3->value();
        QMessageBox t(this);                                //整一个出车成功的提示
        t.setIcon(QMessageBox::Information);//设置图标类型
        t.setStandardButtons(QMessageBox::Ok);
        t.setWindowTitle("出车成功");
        Car* NowCar=N->P->CheckCar2(i);
        NowCar->SetOut(hour,min);           //设置离开时间
        QString  str="车牌号为"+NowCar->Num+"的"+NowCar->Band+"离开"
                +QString::number(i)+"号车位！！"+"应收费"
                + QString::number(N->P->TakeCar(i,N->T,N->M))+"元";

         t.setText(str);
         if(t.exec()==QMessageBox::Ok)
         {
             t.close();
         }
         if(N->L->LineSize()!=0)                     //队伍里有车在排队时，让车子入场
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

}
