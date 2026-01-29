#ifndef REPUTATION_H
#define REPUTATION_H

#include <QString>
#include "../locations/loc_enums.h"

class Game;

class Reputation
{
public:
    Reputation(Game* ptr);
    QString repDesc();
    int repGet();
    void repSet(int val);
    void repEdit(int val, LocId loc);
    int repFnRevise(int val);
    void repIncreaseAll();
    void repCheckRange();
    void recalcGorslut();
private:
    QString str(int id);
    int m_range{500};
    int m_divRep{500};
    Game* root;
};

#endif // REPUTATION_H
