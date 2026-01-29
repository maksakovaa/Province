#include "reputation.h"
#include "../game.h"
#include "../Functions.h"

Reputation::Reputation(Game *ptr): root(ptr) {}

QString Reputation::repDesc()
{
    QString result;
    std::unordered_map<LocId, QString> repPoint;

    repPoint[lgorodok] = str(6);
    repPoint[lgadukino] = str(7);
    repPoint[lsouth] = str(8);
    repPoint[lcenter] = str(9);
    repPoint[lnorth] = str(10);
    repPoint[ldachi] = str(11);
    repPoint[lunicampus] = str(12);

    if(root->getMainLoc() == lgadukino)
        result = repPoint[lgadukino] + str(root->vEvent(gad_woman_knowsex) + 5);
    else
        result = repPoint[root->getMainLoc()] + str(root->vRep(root->getMainLoc()) / m_range);
    return result;
}

int Reputation::repGet()
{
    repCheckRange();
    return root->vRep(root->getMainLoc()) / m_range;
}

void Reputation::repSet(int val)
{
    root->vRep(root->getMainLoc()) = val * m_range + m_range / 5;
    repCheckRange();
}

void Reputation::repEdit(int val, LocId loc)
{
    LocId point;
    if(loc != lgorodok || loc != lgadukino || loc != lsouth || loc != lcenter || loc != lnorth || loc != ldachi || loc != lunicampus)
    {
        point = root->getMainLoc();
    }
    else point = loc;
    root->vRep(point) -= val;
    repCheckRange();
    if(val < 0) root->sendNotif(str(13));
    if(val > 0) root->sendNotif(str(14));
}

int Reputation::repFnRevise(int val)
{
    int result = 0;
    if(val / m_divRep == 0) result = 1;
    if(val / m_divRep == 1)
    {
        if(getRandInt(1,2) == 1)
            result = 1;
        else
            result = 0;
    }
    if(val / m_divRep == 2)
    {
        if(getRandInt(1,3) == 1)
            result = 1;
        else
            result = 0;
    }
    if(val / m_divRep == 3)
    {
        if(getRandInt(1,4) == 1)
            result = 1;
        else
            result = 0;
    }
    if(val / m_divRep == 4)
    {
        if(getRandInt(1,5) == 1)
            result = 1;
        else
            result = 0;
    }
    return result;
}

void Reputation::repIncreaseAll()
{
    root->vRep(lgorodok) -= repFnRevise(root->vRep(lgorodok));
    root->vRep(lsouth) -= repFnRevise(root->vRep(lsouth));
    root->vRep(lcenter) -= repFnRevise(root->vRep(lcenter));
    root->vRep(lnorth) -= repFnRevise(root->vRep(lnorth));
    root->vRep(ldachi) -= repFnRevise(root->vRep(ldachi));
    root->vRep(lunicampus) -= repFnRevise(root->vRep(lunicampus));
}

void Reputation::repCheckRange()
{
    if(root->vRep(root->getMainLoc()) < 0) root->vRep(root->getMainLoc()) = 0;
    if(root->vRep(root->getMainLoc()) >= m_range * 5)
        root->vRep(root->getMainLoc()) = m_range * 5 - 1;
}

void Reputation::recalcGorslut()
{
    if(root->vEvent(GorSlut) == 0)
        root->vRep(lgorodok) = 0;
    else if(root->vEvent(GorSlut) == 1)
        root->vRep(lgorodok) = m_range;
    else if(root->vEvent(GorSlut) == 2)
        root->vRep(lgorodok) = m_range * 2;
    else if(root->vEvent(GorSlut) == 3)
        root->vRep(lgorodok) = m_range * 3;
    else
        root->vRep(lgorodok) = m_range * 4;
}

QString Reputation::str(int id)
{
    QString str[15];
    str[0] = " вас считают приличной девушкой.";
    str[1] = " вы слывете девушкой, которую легко развести на секс.";
    str[2] = " вас считают давалкой.'";
    str[3] = " вас считают общей безотказной давалкой, которую можно трахать компаниями.";
    str[4] = " вы пользуетесь дурной известностью как шлюха, продающаяся за деньги.";
    str[5] = " вас считают проституткой.";
    str[6] = "В Павлово";
    str[7] = "В деревне";
    str[8] = "В Южном районе";
    str[9] = "В Центральном районе";
    str[10] = "В Северном районе";
    str[11] = "В Дачном массиве";
    str[12] = "В университете";
    str[13] = "Ваша репутация ухудшилась!";
    str[14] = "Ваша репутация улучшилась!";
    return str[id];
}
