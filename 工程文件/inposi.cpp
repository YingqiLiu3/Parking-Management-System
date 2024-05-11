#include "inposi.h"
#include "ui_inposi.h"

InPosi::InPosi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InPosi)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(0);      //设置一下输入框的取值范围
    ui->spinBox->setMaximum(23);
    ui->spinBox_2->setMinimum(0);
    ui->spinBox_2->setMaximum(59);
    setWindowTitle("车辆入场");
}




void InPosi::Add(Lot *p)
{
    N=p;
    int i;                  //同时开始设置下拉选项

    for(i=1;i<=N->Pn;i++)
    {
        if(N->P->CheckPosi(i))      //如果空位上没车,就把这个位置设为下拉选项
        {
            ui->comboBox->addItem(QString::number(i));
        }
    }
    QString str="车牌号为"+N->L->line.head()->Num+"的"+N->L->line.head()->Band+"正在进入停车位置！";  //把标题设置一下
    ui->label->setText(str);
}


InPosi::~InPosi()
{
    delete ui;
}

void InPosi::on_pushButton_clicked()
{
    int hour=ui->spinBox->value();
    int min=ui->spinBox_2->value();
    QString Istr=ui->comboBox->currentText();
    int i=Istr.toInt();                         //将下拉选项里的车位转成int
    N->P->AddPark(i,(N->L->TakeLine()));
    Car *NowCar=N->P->CheckCar2(i);             //设置车的入场时间
    NowCar->SetIN(hour,min);
    accept();
}
