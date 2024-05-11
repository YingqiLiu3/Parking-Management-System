#include "lot.h"
#include"QDebug"

Lot::Lot(int l,int p)
    :Ln(l),Pn(p)
{
    T=30;
    M=1.5;
    L=new Line();
    P=new Park();
    Car *Now;
    int i,hour,min;
    QString Num,Band,del;
    query.exec("select * from park");               //读取数据
    while(query.next())
    {
        i=query.value(0).toInt();
        Num=query.value(1).toString();
        Band=query.value(2).toString();
        hour=query.value(3).toInt();
        min=query.value(4).toInt();
        Now= new Car(Num,Band);
        Now->SetIN(hour,min);
        P->AddPark(i,Now);
    }
    query.exec("drop table park");
    query.exec("select * from line");
    while(query.next())
    {
        Num=query.value(0).toString();
        Band=query.value(1).toString();
        L->AddLine(Num,Band);       //排到队伍里
    }
     query.exec("drop table line");
}
void Lot::InPark(int i, int hour, int min)
{
    P->AddPark(i,L->TakeLine());        //将队伍里第一个车加到停车场，并将其从队伍中删除
    Car *NowCar=P->CheckCar2(i);
    NowCar->SetIN(hour,min);            //设置车子的入场时间
}
Lot::~Lot()
{
    query.exec(" create table park (Id int primary key,Num varchar(20),Band varchar(20),Hour int,Min int )");
    query.exec(" create table line ( Num varchar(20),Band varchar(20) )");

    QMap<int, Car*>::iterator iter=P->park.begin();
    QString str;
    for(;iter!=P->park.end();iter++)
    {
        str="insert into park values(";
        str+=QString::number(iter.key());
        str+=',';
        str+='\'';
        str+=iter.value()->Num;
        str+='\'';
        str+=',';
        str+='\'';
        str+=iter.value()->Band;
        str+='\'';
        str+=',';
        str+=QString::number(iter.value()->InTime.Hour);
        str+=',';
        str+=QString::number(iter.value()->InTime.Min);       //将所以对象的信息读入数据库
        str+=')';
        query.exec(str);
    }

    Car*Now;
    while(L->LineSize()!=0)
    {
        str="insert into line values('";
        Now=L->TakeLine();
        str+=Now->Num;
        str+='\'';
        str+=',';
        str+='\'';
        str+=Now->Band;
        str+="')";
        query.exec(str);
       //将队伍上的的信息写入
    }

}
