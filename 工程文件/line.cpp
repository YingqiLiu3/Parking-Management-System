#include "line.h"

Line::Line()
{

}
void Line::AddLine(QString Num,QString Band)
{
    Car *p=new Car(Num,Band);
    line.enqueue(p);
}
Line::~Line()
{
    line.clear();
}
Car *Line::TakeLine()
{
   return line.dequeue();
}
Park::Park()
{

}

QString Park::ShowAll()
{
    QString str;
    QMap<int, Car*>::iterator iter=park.begin();
    for(;iter!=park.end();iter++)
    {
        str=str+"停车位："+QString::number(iter.key())+"号 "+
               +"车牌号："+iter.value()->Num
               +" 品牌："+iter.value()->Band+
                +" 入场时间"+iter.value()->InTime.ShowTime()+'\n'+'\n';
    }
    return str;
}
int Line::LineSize()
{
    return line.size();
}
int Park::ParkSize()
{
    return park.size();
}
void Park::AddPark(int i, Car *p)
{
    park[i]=p;
}
int Park::CheckPosi(int i)
{
    return !park.count(i);
}
int Park::CheckCar1(QString Num)
{
    QMap<int, Car*>::iterator iter=park.begin();
    for(;iter!=park.end();iter++)
    {
        if(iter.value()->Num==Num)
        {
            return iter.key();
        }
    }
    return 0;
}
Car *Park::CheckCar2(int i)
{
    return park[i];
}

float Park::TakeCar(int i,int T,float M)
{
    Car * Now=CheckCar2(i);
    int in=Now->InTime.Hour*60+Now->InTime.Min;
    int out=Now->OutTime.Hour*60+Now->OutTime.Min;
    int time=out-in;
    float Money=time/T*M;
    if(Money>=30)
    {
        Money=30;
    }
    park.remove(i);
    return Money;
}
