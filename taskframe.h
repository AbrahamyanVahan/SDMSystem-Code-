#ifndef TASKFRAME_H
#define TASKFRAME_H

#include <QFrame>
#include <QSqlTableModel>

namespace Ui {
class taskFrame;
}

class taskFrame : public QFrame
{
    Q_OBJECT

public:
    explicit taskFrame(QWidget *parent = nullptr,QString status=0);
    ~taskFrame();

private slots:


    void on_CrateTaskButton_clicked();

    void on_cancelButton_clicked();

    void on_CreateButton_clicked();

    void on_addPushButton_clicked();





    void on_delButton_clicked();

    void on_TaskTable_clicked(const QModelIndex &index);





private:
    Ui::taskFrame *ui;
     QSqlTableModel *t_model;
     inline static QSqlQuery *query1;
     QString status;
     int row;
};

#endif // TASKFRAME_H
