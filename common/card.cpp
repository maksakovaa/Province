#include "card.h"
#include "../Functions.h"

void Card::init(int count, int min)
{
    card = 1;
    Count_card = count;
    Time_min_card = min;
}

int Card::check()
{
    int result{0};
    if (card == 0)
        result = 0;
    else if (card > 0 && Count_card == 0)
        result =  0;
    else if (card > 0 && Count_card > 0)
        result = 1;
    return result;
}

QString Card::getCard()
{
    randCard = Count_card/divisor_Count_card;
    if(randCard == 0) randCard = 1;
    Count_card -= 1;
    std::vector<QString> papka;
    papka.push_back("a");
    papka.push_back("b");
    papka.push_back("c");
    papka.push_back("d");
    papka.push_back("j");
    int i = getRandInt(0,4);
    int b;
    if (i == 4)
        b = getRandInt(1,2);
    else
        b = getRandInt(2,14);
    return "data/qwest/card/" + papka[i] + "/" + papka[i] + intQStr(b);
}
int Card::getCardTime()
{
    return Time_min_card;
}

int Card::getCardHorny()
{
    return randCard;
}
