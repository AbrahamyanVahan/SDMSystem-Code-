#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include<QString>
#include<QMessageBox>
#include <QSqlRecord>
#include <QDebug>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);


}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_nextButton_clicked()
{
    QString name= ui->nameLine->text();
    QString surname=ui->surnameLine->text();
    QString dateBirth=ui->dateEdit->text();
    QString email=ui->emailLine->text();
    QString password=ui->passwordLine->text();
    QString conpassword=ui->conPasswordLine->text();
    if(name.size()!=0&&surname.size()!=0&&email.size()!=0&&(ui->radioButton->isChecked()||ui->radioButton_2->isChecked()))
    {
         QString status;
        if(ui->radioButton->isChecked())
        {
            status="Admin";
        }
        else
        {
            status="Student";
        }

        if(password.size()>=8&&password==conpassword)
        {
             QMessageBox::information(this,"Registration complte","Welcome to SDMS");
            QString strF=
                    "INSERT INTO StudentInfo(Name,Surname,Date,Email,Password,Status)"
                    "VALUES ('%1','%2','%3','%4','%5','%6')";
            QString str=strF.arg(name).arg(surname).arg(dateBirth).arg(email).arg(password).arg(status);
            ::MainWindow::query->exec(str);

            ui->nameLine->setText("");
            ui->surnameLine->setText("");
            ui->emailLine->setText("");
            ui->passwordLine->setText("");
            ui->conPasswordLine->setText("");

        }
        else
        {
             QMessageBox::warning(this,"Registration failed","Passwords do not mutch\nPlease try again");
        }
    }
    else if(name.size()==0)
    {
        QMessageBox::warning(this,"Registration","Please fill your name ");
    }
    else if(surname.size()==0)
    {
        QMessageBox::warning(this,"Registration","Please fill your surname ");
    }
    else if(email.size()==0)
    {
        QMessageBox::warning(this,"Registration","Please fill your email ");
    }
    else if(!(ui->radioButton->isChecked()||ui->radioButton_2->isChecked()))
    {
        QMessageBox::warning(this,"Registration","Please select your role ");

    }
}


void RegisterWindow::on_cancelButton_clicked()
{
    this->close();
    MainWindow *m_window=new MainWindow();
    m_window->show();
}


void RegisterWindow::on_signInButton_clicked()
{
    this->close();
    MainWindow *m_window=new MainWindow();
    m_window->show();
}

