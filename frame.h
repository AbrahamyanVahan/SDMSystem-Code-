#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QString>
#include <mainwindow.h>
namespace Ui {
class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr,QString gmail=0);
    ~Frame();

private:
    Ui::Frame *ui;
};

#endif // FRAME_H
