#ifndef INPOSI_H
#define INPOSI_H

#include <QDialog>
#include"lot.h"
namespace Ui {
class InPosi;
}

class InPosi : public QDialog
{
    Q_OBJECT

public:
    explicit InPosi(QWidget *parent = nullptr);
    ~InPosi();
    Lot *N;
    void Add(Lot *p);

private slots:
    void on_pushButton_clicked();

private:
    Ui::InPosi *ui;
};

#endif // INPOSI_H
