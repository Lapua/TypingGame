#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wordLayout = new QHBoxLayout;
    QString word = "alice";
    wordLabel = new QLabel*[10];
    for (int i = 0; i < 10; i++) {
        wordLabel[i] = new QLabel;
    }
    for (int i = 0; i < word.length(); i++) {
        wordLabel[i] -> setText(word.at(i));
        wordLayout -> addWidget(wordLabel[i]);
    }



    rootLayout = new QVBoxLayout;

    setLayout(wordLayout);
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << QKeySequence(event->key()).toString();
}
