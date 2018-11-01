#ifndef WORDLIST_H
#define WORDLIST_H

#include <QString>
#include <QWidget>

class WordList
{
private:
    QStringList qstrl = {
        "frost",
        "alice"
    };

public:
    QString getWordList()
    {
        QString str = qstrl.takeLast();
        return str;
    }

    bool isEmpty()
    {
        return qstrl.isEmpty();
    }
};

#endif // WORDLIST_H
