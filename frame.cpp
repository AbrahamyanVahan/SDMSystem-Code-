#include "frame.h"
#include "ui_frame.h"
#include "mainwindow.h"
#include <QSqlRecord>

Frame::Frame(QWidget *parent,QString gmail ) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    QString username;
    QString usersurname;
    QString status;
    if(!::MainWindow::query->exec("SELECT * FROM StudentInfo"))
    {
        qDebug()<<"error";
    };
    QSqlRecord record=::MainWindow::query->record();
    QString data_email;
    while(::MainWindow::query->next())
    {
        data_email=MainWindow::query->value(record.indexOf("Email")).toString();
        if(data_email==gmail)
        {

            username=MainWindow::query->value(record.indexOf("Name")).toString();
            usersurname=MainWindow::query->value(record.indexOf("Surname")).toString();
            status=MainWindow::query->value(record.indexOf("Status")).toString();
            ui->labelname->setText(username);
            ui->labelsurn->setText(usersurname);
            ui->labelstatus->setText(status);
        }

    }

}

Frame::~Frame()
{
    delete ui;
}
