#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"loancalculator.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;

    void  connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Qt/login2.sqlite");
        if(!mydb.open()){
            qDebug()<<("failed to open");
        return false;
        }
        else{
            qDebug()<<("connected.....");
            return true;
        }
    }

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;

};
#endif // LOGIN_H
