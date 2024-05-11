#ifndef PASS_CHANGE_H
#define PASS_CHANGE_H

#include <QDialog>

namespace Ui {
class Pass_Change;
}

class Pass_Change : public QDialog
{
    Q_OBJECT

public:
    explicit Pass_Change(QWidget *parent = nullptr);
    ~Pass_Change();

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::Pass_Change *ui;
};

#endif // PASS_CHANGE_H
