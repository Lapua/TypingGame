#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include "word.h"
#include "score.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QHBoxLayout *lay;
    Word *wordWidget;
    Score *scoreWidget;
};

#endif // WIDGET_H
