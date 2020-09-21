#include "loancalculator.h"
#include "ui_loancalculator.h"
#include<QMessageBox>

loancalculator::loancalculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loancalculator)
{
    ui->setupUi(this);
    login conn;

            if(!conn.connOpen())
                ui-> label_sec_status->setText("failed to open");
            else
                ui-> label_sec_status->setText("connected.....");

}

loancalculator::~loancalculator()
{
    delete ui;
}

void loancalculator::on_pushButton_clicked()
{
 Calculate();
}
void loancalculator::Calculate()
{
   QString amount,month,rate;
   amount=ui->lineEdit_amount->text();
   month=ui->lineEdit_month->text();

    double interest=(amount.toDouble()*4*month.toDouble()/100);
    double totalamount=(amount.toDouble())+(amount.toDouble()*4*month.toDouble()/100);
    QString Result;
    Result.sprintf("%f",interest);
    ui->lineEdit_interest->setText(Result);
    QString Result2;
    Result2.sprintf("%f",totalamount);
    ui->lineEdit_totalamount->setText(Result2);
}

void loancalculator::on_pushButton_2_clicked()
{
    login conn;

    QString amount,month;
    amount=ui->lineEdit_amount->text();
    month=ui->lineEdit_month->text();



    if(!conn.connOpen()){
        qDebug()<<"failed to open data base";
        return;

    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare( "insert into login2 (amount,month) values ('"+amount+"','"+ month+"')");

    if(qry.exec( ))

    {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       conn. connClose();
    }
    else{

         QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}
