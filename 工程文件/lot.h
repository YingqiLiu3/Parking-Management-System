#ifndef LOT_H
#define LOT_H
#include"line.h"
#include<QFile>
#include<QTextStream>
#include<QSqlDatabase>
#include<QSqlQuery>
class Lot
{

public:
    Lot(int L=3,int P=3);//两个参数分别为最大个数,并且读取文件中的数据
    Line *L;
    Park *P;
    int Ln;     //队列的最大车辆个数
    int Pn;     //停车位的个数
    void InPark(int i,int hour,int min);// 从队伍中进一辆车到停车场中
    ~Lot();             //将停车场上的车和队伍里的车存入文件中
    int T;                      //收费周期
    float M;                      //收费金额
private:
     QSqlQuery query;
};

#endif // LOT_H
