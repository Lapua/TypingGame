#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wordLayout = new QHBoxLayout;
    wordLabel = new QLabel*[10];

    for (int i = 0; i < 10; i++) {
        wordLabel[i] = new QLabel;
    }

    fontColor = new QPalette;
    *fontColor = wordLabel[0] -> palette();
    fontColor -> setColor(QPalette::WindowText, Qt::gray);

    setLayout(wordLayout);
}

Widget::~Widget()
{

}

void Widget::NextWord()
{

    *word = WordList::getWordList();
    for (int i = 0; i < word -> length(); i++) {
        wordLabel[i] -> setText(word -> at(i));
        wordLayout -> addWidget(wordLabel[i]);
     }

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    QKeySequence seq(event -> key());
    qDebug() << seq.toString();
    qDebug() << seq.count();

    QString key = QKeySequence(event -> key()).toString();
    QChar answer = word -> at(currentChar).toUpper();
    if (key == answer) {
        wordLabel[currentChar] -> setPalette(*fontColor);
        currentChar++;
    }
}
