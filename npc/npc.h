#ifndef NPC_H
#define NPC_H

#include <QString>
#include "../locations/loc_enums.h"
#include "npc_enum.h"

struct NPC
{
    QString name;
    QString surname;
    QString nickname;
    int relation;
    npcGroup group;
    int dick;
    int sex;
    int silavag;
    bool know;
    int talk_count = 0;
    LocId location;
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
