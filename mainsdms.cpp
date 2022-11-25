#include "mainsdms.h"
#include "ui_mainsdms.h"
#include "frame.h"
#include <QPixmap>

MainSDMS::MainSDMS(QWidget *parent,QString mail) :
    QMainWindow(parent),
    ui(new Ui::MainSDMS)
{
    ui->setupUi(this);
    is_home=false;
    is_myTask=false;
    click_task=false;
    this->gmail=mail;

}

MainSDMS::~MainSDMS()
{

    delete ui;
}
void MainSDMS::on_mainButton_clicked()
{
    if(!ui->frame->isHidden())
    {
        ui->frame->hide();
    }
    else
    {
        ui->frame->show();
    }
}
void MainSDMS::on_homeButon_clicked()
{
    if(is_home==false&&is_myTask==false)
    {
        is_home=true;
        is_myTask=false;
        hF=new Frame(ui->mainFrame,gmail);
        hF->show();
    }
    else if(is_home==false&&is_myTask==true)
    {
        is_home=true;
        is_myTask=false;
        hF=new Frame(ui->mainFrame,gmail);
        tF->hide();
        hF->show();
    }
}


void MainSDMS::on_mytasksButton_clicked()
{
    if(is_home==false&&is_myTask==false)
    {
        is_home=false;
        is_myTask=true;
        if(click_task==false)
        {
            tF=new taskFrame(ui->mainFrame,gmail);
            click_task=true;
        }

        tF->show();
    }
    else if(is_home==true&&is_myTask==false)
    {
        is_home=false;
        is_myTask=true;
        tF=new taskFrame(ui->mainFrame,gmail);
        hF->hide();
        tF->show();
    }
}

