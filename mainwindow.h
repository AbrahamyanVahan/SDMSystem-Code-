#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <registerwindow.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SignUpButton_clicked();

    void on_pushButton_4_clicked();

    void on_nextButton_clicked();
public:
    inline static QSqlDatabase database;
    inline static QSqlQuery *query;
private:
    Ui::MainWindow *ui;

    QSqlTableModel *t_model;


};
#endif // MAINWINDOW_H
