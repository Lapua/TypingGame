#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QKeyEvent>
#include <QKeySequence>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel **wordLabel;
    QLabel *wordLabel1;
    QLabel *wordLabel2;
    QLabel *wordLabel3;
    QLabel *wordLabel4;
    QLabel *wordLabel5;
    QVBoxLayout *rootLayout;
    QHBoxLayout *wordLayout;

    void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
