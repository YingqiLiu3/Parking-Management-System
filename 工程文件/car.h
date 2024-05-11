#ifndef CAR_H
#define CAR_H
#include<QString>
class Time			//时间类
{
    private:
        int Hour;
        int Min;
    public:
        void SetTime(int Hou,int Mi);
        QString ShowTime();
        Time();
        friend class Lot;
        friend class Park;
};

class Car
{
    private:
        QString Num;           //车牌号
        QString Band;          //品牌
    public:
        Car(QString num,QString band);  //第一个是车牌号，第二个是品牌
        Time InTime;                    //进入停车场的时间
        Time OutTime;                   //出停车场的时间
        QString Show();                 //返回车牌号和品牌,入场时间
        void SetIN(int hou,int min);                   //设置进场时间
        void SetOut(int hou,int min);                  //设置出场时间
        friend class Park;
        friend class InPosi;
        friend class OutPosi;
        friend class Check;
        friend class Lot;
};





#endif // CAR_H
