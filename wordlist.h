#ifndef WORDLIST_H
#define WORDLIST_H

#include <QStringList>
#include <QWidget>

class WordList : public QWidget
{
public:
    static QString getWordList()
    {
        QStringList qstr = {
            "alice",
            "frost"
        };

        return qstr.takeLast();
    }
};

#endif // WORDLIST_H
