#ifndef INLINE_H
#define INLINE_H

#include <QDialog>
#include"lot.h"
#include<QMessageBox>
#include"inposi.h"
namespace Ui {
class InLine;
}

class InLine : public QDialog
{
    Q_OBJECT

public:
    explicit InLine(QWidget *parent = nullptr);
    ~InLine();
    Lot *N;
    void Add(Lot *p);
private slots:
    void on_pushButton_clicked();

private:
    Ui::InLine *ui;
};

#endif // INLINE_H
