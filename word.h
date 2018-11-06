#ifndef WORD_H
#define WORD_H

#include <QWidget>
#include <QtWidgets>
#include <QKeyEvent>
#include <QKeySequence>
#include <QPalette>
#include <QPixmap>
#include <QFont>
#include <wordlist.h>
#include <QDebug>

class Word : public QWidget
{
    Q_OBJECT

public:
    Word(QWidget *parent = 0);
    ~Word();

private:
    QPalette *fontColor;
    QStringList *words;
    QString *engWord;
    QString *jpnWord;
    QLabel **wordLabel;
    QLabel *jpnLabel;
    QLabel *imageLabel;
    QFont *engFont;
    QFont *jpnFont;
    QPixmap *imagePixmap;
    QHBoxLayout *wordLayout;
    QVBoxLayout *wordAndImage;
    WordList *wordList;
    int currentChar = 0;
    bool keyEnable = true;

    void keyPressEvent(QKeyEvent *event);
    void NextWord();
    void NextImage(QString fileName);
};

#endif
