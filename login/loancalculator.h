#ifndef LOANCALCULATOR_H
#define LOANCALCULATOR_H

#include <QDialog>
#include "login.h"

namespace Ui {
class loancalculator;
}

class loancalculator : public QDialog
{
    Q_OBJECT

public:

    explicit loancalculator(QWidget *parent = nullptr);
    ~loancalculator();
protected:
    void Calculate();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::loancalculator *ui;
};

#endif // LOANCALCULATOR_H
