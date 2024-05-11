#ifndef OUTPOSI_H
#define OUTPOSI_H
#include"lot.h"
#include <QDialog>
#include<QMessageBox>
#include"inposi.h"
namespace Ui {
class OutPosi;
}

class OutPosi : public QDialog
{
    Q_OBJECT

public:
    explicit OutPosi(QWidget *parent = nullptr);
    ~OutPosi();
    Lot *N;
    void Add(Lot *p);

private slots:
    void on_pushButton_clicked();

private:
    Ui::OutPosi *ui;
};

#endif // OUTPOSI_H
