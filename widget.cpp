#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    lay = new QVBoxLayout;
    wordWidget = new Word;
    lay -> addWidget(wordWidget);

    setLayout(lay);

    wordWidget -> setFocus();
}
