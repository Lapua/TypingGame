#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wordLayout = new QHBoxLayout;
    wordLabel = new QLabel*[10];

    for (int i = 0; i < 10; i++) {
        wordLabel[i] = new QLabel;
    }

    wordList = new WordList;
    word = new QString;
    fontColor = new QPalette;
    *fontColor = wordLabel[0] -> palette();

    NextWord();

    setLayout(wordLayout);
}

Widget::~Widget()
{
}

void Widget::NextWord()
{
    if (wordList -> isEmpty()) {
        keyEnable = false;
        return;
    }

    fontColor -> setColor(QPalette::WindowText, Qt::black);
    currentChar = 0;
    *word = wordList -> getWordList();
    for (int i = 0; i < word -> length(); i++) {
        wordLabel[i] -> setText(word -> at(i));
        wordLabel[i] -> setPalette(*fontColor);
        wordLayout -> addWidget(wordLabel[i]);
    }
    fontColor -> setColor(QPalette::WindowText, Qt::gray);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (! keyEnable) {
        return;
    }

    QString key = QKeySequence(event -> key()).toString();
    QChar answer = word -> at(currentChar).toUpper();
    if (key == answer) {
        wordLabel[currentChar] -> setPalette(*fontColor);
        currentChar++;
    }

    if (currentChar == word -> length()) {
        for (int i = 0; i < word -> length(); i++) {
            wordLayout -> removeWidget(wordLabel[i]);
        }
        NextWord();
    }
}
