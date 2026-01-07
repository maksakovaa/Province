#ifndef NPC_H
#define NPC_H

#include <QString>

enum BoyType { tgopnik, tnormal, tmazor };
enum BoyChar { csoft, cnormal, cimpudent };

struct NPC
{
    QString name;
    QString surname;
    QString nickname;
    int relation;
    int group;
    int dick;
    int sex;
    int silavag;
    int know;
    int talk_count = 0;
};

struct NPCboyfriend
{
    QString name;
    QString surname;
    QString nickname;
    int relation;
    int group;
    int dick;
    int sex;
    int silavag;
    int know;
    int talk_count = 0;
    //параметры для парней для отношений
    int meet_day = 0;
    int boyfriend = 0;
    BoyType boy_type;
    BoyChar boy_character;
    bool izvrat;
    int boy_beauty;
    int boy_haircolor;
    int boy_tits;
    int boy_body;
};

#endif
