#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    lay = new QHBoxLayout;
    wordWidget = new Word;
    scoreWidget = new Score;
    lay -> addWidget(wordWidget);
    lay -> addWidget(scoreWidget);

    setLayout(lay);

    wordWidget -> setFocus();
}
