#include "word.h"

Word::Word(QWidget *parent)
    : QWidget(parent)
{
    wordLayout = new QHBoxLayout;
    wordLabel = new QLabel*[20];
    for (int i = 0; i < 20; i++) {
        wordLabel[i] = new QLabel;
    }

    wordList = new WordList;
    word = new QString;
    fontColor = new QPalette;
    *fontColor = wordLabel[0] -> palette();

    wordAndImage = new QVBoxLayout;
    imagePixmap = new QPixmap;
    imageLabel = new QLabel();
    //imageLabel -> setPixmap(imagePixmap -> scaled(400, 400, Qt::KeepAspectRatio));
    wordAndImage -> addWidget(imageLabel);
    wordAndImage -> addLayout(wordLayout);

    NextWord();
    setLayout(wordAndImage);
    setFocus();
}

Word::~Word()
{
}

void Word::NextWord()
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

    NextImage(*word);
}

void Word::NextImage(QString fileName)
{
    imagePixmap -> load(":/actor/" + fileName + ".jpg");
    imageLabel -> setPixmap(imagePixmap -> scaled(400, 400, Qt::KeepAspectRatio));
}

void Word::keyPressEvent(QKeyEvent *event)
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
