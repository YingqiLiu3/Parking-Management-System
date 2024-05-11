#ifndef P_H
#define P_H

#include <QMainWindow>
#include"lot.h"
namespace Ui {
class P;
}

class P : public QMainWindow
{
    Q_OBJECT

public:
    explicit P(QWidget *parent = nullptr);
    ~P();
    Lot *N;
    void Add(Lot *p);
private slots:
    void on_pushButton_clicked();       //登录键

    void on_pushButton_2_clicked();     //进入修改密码的页面

private:
    Ui::P *ui;
};
QString Password();
QString Password_Change(QString);
#endif // P_H
