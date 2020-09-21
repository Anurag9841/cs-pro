#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);



    if(!connOpen())
        ui->label_3->setText("failed to open");
    else
        ui->label_3->setText("connected.....");

}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();
    if(!connOpen()){
        qDebug()<<"failed to open data base";
        return;

    }
    connOpen();
    QSqlQuery qry;
    qry.prepare( "select * from login2 where username='"+ username+"'and password='"+password+"'");

    if(qry.exec( ))

    {
        int count=0;
        while(qry.next())
        {
            count++;

        }

        if(count==1){
            ui->label_3->setText("username and password is correct");
             connClose();
            this->hide();
            loancalculator loancalculator;
             loancalculator.setModal(true);
              loancalculator.exec();

        }
        if(count>1)
            ui->label_3->setText("duplicate username and password");
        if(count<1)
            ui->label_3->setText("username and password is notcorrect");
    }


}
