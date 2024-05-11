#ifndef FEE_H
#define FEE_H

#include <QDialog>
#include<lot.h>
namespace Ui {
class Fee;
}

class Fee : public QDialog
{
    Q_OBJECT

public:
    explicit Fee(QWidget *parent = nullptr);
    ~Fee();
    void Add(Lot *p);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Fee *ui;
    Lot *N;
};

#endif // FEE_H
