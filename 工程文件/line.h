#ifndef LINE_H
#define LINE_H
#include<QQueue>
#include<QMap>
#include"car.h"
class Line
{
    private:
        QQueue<Car*>line;
    public:
        Line();
        ~Line();                                             //析构函数清除队列里的东西
        void AddLine(QString Num,QString Band);              //往队伍里加一辆车，参数为车的车牌号、品牌
        Car* TakeLine();                                     //返回队伍最前车的地址，再删除这个,也就是将车子拿出来
        int LineSize();
        friend class InPosi;
};
class Park
{
    private:
        QMap<int,Car*>park;         //整形是车位序号，第二个是车子地址
    public:
        Park();
        void AddPark(int i,Car*p);   //往停车场加一辆车，第一个参数是车位序号，第二个是车子
        int CheckPosi(int i);        //查看i号车位有没有车，没车返回1，有车返回0
        int CheckCar1(QString Num);  //按照车牌号寻找车辆，找到了返回车位，没找到返回0
        Car* CheckCar2(int i);        //按车位寻找车辆，返回车对象的地址
        float TakeCar(int i ,int T,float M);       //按车位把车提走，返回停车费
        int ParkSize();               //返回park里车辆的个数
        QString ShowAll();             //返回位的全部情况
        friend class Lot;

};

#endif // LINE_H
