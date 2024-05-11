#include "p.h"
#include "ui_p.h"
#include"parking.h"
#include<QTextStream>
#include<QFile>
#include<QDebug>
#include<pass_change.h>
#include<QWidget>
P::P(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::P)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    setWindowTitle("Login");
}
void P::Add(Lot *p)
{
    N=p;
}
P::~P()
{
    delete ui;
}
QString Password()     //提取当前密码
{

    QFile e("C:\\Users\\Inch Lau\\Desktop\\P\\Password.txt");
    e.open(QIODevice::ReadOnly);
    QTextStream in(&e);
    QString line=in.readLine();
    e.close();
    return line;
}
void P::on_pushButton_clicked()     //登录选项
{

    QString str=ui->lineEdit_2->text();
    if(str==Password())
    {
        Parking *p= new Parking();
        p->Add(N);
        p->show();
         hide();
    }
    else
    {
        ui->label_4->setText("密码错误，请重新输入！！");
    }
    //qDebug()<<ui->comboBox->currentText();        //输出用户名
}

QString Password_Change(QString str)     //修改当前密码，参数为新密码
{
    QFile f("Password.txt");
    f.open(QIODevice::WriteOnly);
    QTextStream out(&f);
    out<<str;
    f.close();
    return str;
}
void P::on_pushButton_2_clicked()   //修改密码的页面
{
    Pass_Change * Change=new Pass_Change();
    Change->show();
    close();
    if(Change->exec()==QDialog::Rejected)
    {
        Change->close();
        show();
    }
}
