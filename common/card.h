#ifndef CARD_H
#define CARD_H

#include <QString>

class Card
{
public:
    Card(){};
    void init(int count, int min);
    int check();
    int getCardTime();
    int getCardHorny();
    QString getCard();
private:
    int divisor_Count_card{6};
    int Count_card{0};
    int randCard;
    int card{0};
    int Time_min_card{0};
};

#endif