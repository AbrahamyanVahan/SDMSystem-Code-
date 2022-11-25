#ifndef MAINSDMS_H
#define MAINSDMS_H

#include <QMainWindow>
#include "frame.h"
#include "taskframe.h"
#include <QString>
namespace Ui {
class MainSDMS;
}

class MainSDMS : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSDMS(QWidget *parent = nullptr,QString mail=0);

    ~MainSDMS();

private slots:



    void on_mainButton_clicked();



    void on_homeButon_clicked();

    void on_mytasksButton_clicked();



private:
    Ui::MainSDMS *ui;
    bool is_home;
    bool is_myTask;
    taskFrame *tF;
      Frame *hF;
    bool click_task;
    QString gmail;



};

#endif // MAINSDMS_H
