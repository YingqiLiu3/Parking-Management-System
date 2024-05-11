#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include"lot.h"
namespace Ui {
class Check;
}

class Check : public QDialog
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = nullptr);
    ~Check();
    Lot *N;
    void Add(Lot *p);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Check *ui;
};

#endif // CHECK_H
