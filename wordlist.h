#ifndef WORDLIST_H
#define WORDLIST_H

#include <QStringList>
#include <QWidget>
#include <QRandomGenerator>
#include <QTime>

class WordList
{
private:
    QStringList engName = {
        "touyamanao",
        "minaseinori",
        "ogurayui",
        "amamiyasora",
        "asakuramomo",
        "hanazawakana",
        "hayamisaori",
        "hidakarina",
        "igutiyuka",
        "kayanoai",
        "kugimiyarie",
        "mimorisuzuko",
        "mizukinana",
        "nannjouyosino",
        "natukawasiina",
        "sakuraayane",
        "satousatomi",
        "takahasirie",
        "taketatuayana",
        "tanedarisa",
        "tomatuharuka",
        "uesakasumire",
        "utidamaaya",
        "yuukiaoi"
    };

    QStringList jpnName = {
        "東山 奈央",
        "水瀬 いのり",
        "小倉 唯",
        "雨宮　天",
        "麻倉 もも",
        "花澤 香菜",
        "早見 沙織",
        "日高 里奈",
        "井口 裕香",
        "茅野 愛衣",
        "釘宮 理恵",
        "三森 すずこ",
        "水樹 奈々",
        "南條 愛乃",
        "夏川 椎菜",
        "佐倉 綾音",
        "佐藤 聡美",
        "高橋 李依",
        "竹達 彩奈",
        "種田 梨沙",
        "戸松 遥",
        "上坂 すみれ",
        "内田 真礼",
        "悠木 碧"
    };

    QRandomGenerator *rand;
    int num;

public:
    WordList()
    {
        rand = new QRandomGenerator(QTime::currentTime().msec());
    }

    QStringList getWordList()
    {
        num = rand -> bounded(engName.count());
        QStringList strList;
        strList.append(engName.takeAt(num));
        strList.append(jpnName.takeAt(num));
        return strList;
    }

    bool isEmpty()
    {
        return engName.isEmpty();
    }
};

#endif // WORDLIST_H
