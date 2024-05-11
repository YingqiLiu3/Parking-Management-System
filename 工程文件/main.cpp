#include "p.h"
#include <QApplication>
#include<QTextStream>
#include<QFile>
#include<QDebug>
#include"car.h"
#include"line.h"
#include"lot.h"
#include<QSqlDatabase>
#include<QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb");
    db.open();
    P w;
    Lot N;
    w.Add(&N);
    w.show();
    return a.exec();
}
