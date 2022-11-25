#include "taskframe.h"
#include "ui_taskframe.h"
#include "mainwindow.h"
#include <QString>
#include <QDebug>
#include<QSqlRecord>
#include<QAction>

taskFrame::taskFrame(QWidget *parent,QString gmail) :
    QFrame(parent),
    ui(new Ui::taskFrame)
{
    ui->setupUi(this);
    ui->studentView->hide();

    QString status;
    //Create new table in Database for Tasks
    ui->CreateBox->hide();
    ui->taskNameLine->setPlaceholderText("Task Name");
    ui->DescriptioEDit->setPlaceholderText("Description");
    this->query1=new QSqlQuery(::MainWindow::database);

    QString task_tables="CREATE TABLE TaskDescript("
                       "TaskName VARCНAR(50),"
                       "Description VARCНAR(50))";
    this->query1->exec(task_tables);
    this->t_model=new QSqlTableModel(this,::MainWindow::database);
    this->t_model->setTable("TaskDescript");
    this->t_model->select();
    ui->TaskTable->setModel(t_model);

    //
    if(!this->query1->exec("SELECT * FROM StudentInfo"))
    {
        qDebug()<<"error";
    };
    QSqlRecord record=::MainWindow::query->record();
    QString data_email;
    while(this->query1->next())
    {
        data_email=this->query1->value(record.indexOf("Email")).toString();
        if(data_email==gmail)
        {
           this-> status=MainWindow::query->value(record.indexOf("Status")).toString();

        }

    }
    //

    QSqlTableModel *mod1=new QSqlTableModel(this,::MainWindow::database);
    mod1->setTable("StudentInfo");
    mod1->select();
    ui->tableView->setModel(mod1);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->setColumnHidden(4,true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSortingEnabled(true);
}

taskFrame::~taskFrame()
{
    delete ui;
}




void taskFrame::on_CrateTaskButton_clicked()
{
    ui->CreateBox->show();
}


void taskFrame::on_cancelButton_clicked()
{
    ui->CreateBox->hide();
}


void taskFrame::on_CreateButton_clicked()
{

    QString t_name=ui->taskNameLine->text();
    QString d_name=ui->DescriptioEDit->toPlainText();
    ui->taskNameLine->clear();
    ui->DescriptioEDit->clear();
    QString comand_string=
            "INSERT INTO TaskDescript(TaskName,Description) "
            "VALUES ('%1','%2')";
    QString data_string=comand_string.arg(t_name).arg(d_name);
    this->query1->exec(data_string);




    ui->CreateBox->hide();
}


void taskFrame::on_addPushButton_clicked()
{
    ui->studentView->show();
    ::MainWindow::database=QSqlDatabase::addDatabase("QSQLITE");
    ::MainWindow::database.setDatabaseName("./SDMSdatabase.db");
    ::MainWindow::database.setUserName("User222");
    ::MainWindow::database.setHostName("");
    ::MainWindow::database.setPassword("SDMSpassword");
    if(::MainWindow::database.open())
    {
           qDebug()<<" open";

    }
    else
    {
        qDebug()<<"failed";
    }

    QSqlTableModel *mod=new QSqlTableModel(this,::MainWindow::database);
    mod->setTable("StudentInfo");
    mod->select();
    ui->studentView->setModel(mod);
    ui->studentView->setColumnHidden(3,true);
    ui->studentView->setColumnHidden(4,true);
    ui->studentView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->studentView->setSortingEnabled(true);






}







void taskFrame::on_delButton_clicked()
{

        t_model->removeRow(row);

}


void taskFrame::on_TaskTable_clicked(const QModelIndex &index)
{
    this->row=index.row();
}














