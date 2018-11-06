#include "word.h"

Word::Word(QWidget *parent)
    : QWidget(parent)
{
    wordLayout = new QHBoxLayout;
    wordLabel = new QLabel*[20];
    for (int i = 0; i < 20; i++) {
        wordLabel[i] = new QLabel;
    }

    jpnLabel = new QLabel;
    wordList = new WordList;
    words = new QStringList;
    engWord = new QString;
    jpnWord = new QString;
    fontColor = new QPalette;
    *fontColor = wordLabel[0] -> palette();

    jpnFont = new QFont;
    jpnFont -> setWeight(QFont::DemiBold);
    jpnFont -> setPixelSize(30);
    engFont = new QFont;
    engFont -> setPixelSize(20);

    wordAndImage = new QVBoxLayout;
    imagePixmap = new QPixmap;
    imageLabel = new QLabel();
    imageLabel -> setAlignment(Qt::AlignCenter);
    imageLabel ->   setFixedSize(400, 400);
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
    *words = wordList -> getWordList();
    *engWord = words -> takeFirst();
    *jpnWord = words -> takeFirst();

    for (int i = 0; i < 20; i++) {
        delete wordLabel[i];
        wordLabel[i] = new QLabel;
    }
    for (int i = 0; i < engWord -> length(); i++) {
        wordLabel[i] -> setText(engWord -> at(i));
        wordLabel[i] -> setPalette(*fontColor);
        wordLabel[i] -> setFont(*engFont);
        wordLayout -> addWidget(wordLabel[i]);
    }
    fontColor -> setColor(QPalette::WindowText, Qt::gray);

    delete jpnLabel;
    jpnLabel = new QLabel(*jpnWord);
    jpnLabel -> setAlignment(Qt::AlignCenter);
    jpnLabel ->setFont(*jpnFont);
    wordAndImage -> addWidget(jpnLabel);

    NextImage(*engWord);
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
    QChar answer = engWord -> at(currentChar).toUpper();
    if (key == answer) {
        wordLabel[currentChar] -> setPalette(*fontColor);
        currentChar++;
    }

    if (currentChar == engWord -> length()) {
        NextWord();
    }
}
