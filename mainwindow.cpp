#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"
#include "mainsdms.h"
#include <QDebug>
#include <QSqlRecord>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    //Create database
    database=QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("./SDMSdatabase.db");
    database.setUserName("User222");
    database.setHostName("");
    database.setPassword("SDMSpassword");
    if(database.open())
    {
           qDebug()<<" open";

    }
    else
    {
        qDebug()<<"failed";
    }

    this->query=new QSqlQuery(database);
    QString dat_tables="CREATE TABLE StudentInfo("
                       "Name VARCНAR(20),"
                       "Surname VARCНAR(20),"
                       "Date VARCНAR(20),"
                       "Email VARCНAR(20),"
                       "Password VARCНAR(20),"
                       "Status VARCHAR(20))";
    query->exec(dat_tables);
    this->t_model=new QSqlTableModel(this,database);
    this->t_model->setTable("StudentInfo");
    this->t_model->select();

    //




}

MainWindow::~MainWindow()
{
    delete ui;
}








void MainWindow::on_SignUpButton_clicked()
{


    this->close();
    RegisterWindow *wr=new RegisterWindow();
    wr->show();

}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();

}


void MainWindow::on_nextButton_clicked()
{
    if(!this->query->exec("SELECT * FROM StudentInfo"))
    {
        qDebug()<<"error";
    };
    QSqlRecord record=this->query->record();
    QString user_email= ui->emailEdit->text();
    QString user_password=ui->passwordEdit->text();

    QString data_email;
    QString data_password;
    bool lock=false;
    // Find email and password in database
    while(query->next())
    {
        data_email=this->query->value(record.indexOf("Email")).toString();
        data_password=this->query->value(record.indexOf("Password")).toString();



        if(data_email==user_email&& data_password==user_password)
        {
            lock=true;
            break;
        }
        else
        {
            lock=false;
            continue;
        }
    }
    if(lock==false)
    {
        ui->warning_label->setText("Invalid email or password");
    }
    else
    {
        // When password and email is correct
        ui->warning_label->setText("");
        this->close();

        MainSDMS *window=new MainSDMS(nullptr,user_email);
        window->show();
    }

}

