#ifndef ALL_H
#define ALL_H

#include <QDialog>
#include"lot.h"
namespace Ui {
class All;
}

class All : public QDialog
{
    Q_OBJECT

public:
    explicit All(QWidget *parent = nullptr);
    ~All();
    Lot *N;
    void Add(Lot *p);
private:
    Ui::All *ui;
};

#endif // ALL_H
