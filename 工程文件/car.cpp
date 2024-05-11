#include "car.h"

Car::Car(QString num,QString band)
    :Num(num),Band(band)
{

}


QString Car::Show()
{
    QString info="车牌号："+Num+"   品牌："+Band
            +"   进场时间："+InTime.ShowTime();
    return info;
}

void Time::SetTime(int hou,int min)
{
    Hour=hou;
    Min=min;
}


void Car::SetIN(int hou, int min)
{
    InTime.SetTime(hou,min);
}


void Car::SetOut(int hou, int min)
{
    OutTime.SetTime(hou,min);
}


Time::Time(){
}

QString Time::ShowTime()
{
    QString str=QString::number(Hour)+"时"+QString::number(Min)+"分";
    return str;
}

