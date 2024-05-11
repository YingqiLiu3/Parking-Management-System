#ifndef PARKING_H
#define PARKING_H
#include"inline.h"
#include <QWidget>
#include"lot.h"
#include"outposi.h"
#include"check.h"
#include"all.h"
#include"fee.h"
namespace Ui {
class Parking;
}

class Parking : public QWidget
{
    Q_OBJECT

public:
    explicit Parking(QWidget *parent = nullptr);
    ~Parking();
    Lot *N;
    void Add(Lot *p);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Parking *ui;
};

#endif // PARKING_H
