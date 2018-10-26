#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QKeyEvent>
#include <QKeySequence>
#include <QPalette>
#include <wordlist.h>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPalette *fontColor;
    QString *word;
    QLabel **wordLabel;
    QHBoxLayout *wordLayout;
    int currentChar = 0;

    void keyPressEvent(QKeyEvent *event);
    void NextWord();
};

#endif // WIDGET_H
