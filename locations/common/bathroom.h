#ifndef BATHROOM_H
#define BATHROOM_H

#include <QObject>
#include "../../items/cloth.h"
#include "../location.h"
#include "bathenums.h"

class LocationHandler;
class Beach;

class BathRoom: public Location
{
    Q_OBJECT
    friend Beach;
public:
    BathRoom(LocationHandler* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void cleanMe();
private slots:
    void slotBathActionHandler(bathActs action);
    void slotPeekActHandler(peekActs action);
    void slotVoyerActHandler(bathVoyerActs action);
private:
//methods
    void actionHandler(QString action) override;
    void peek();
    void makeActBtn(bathActs action);
    void makeVoyerActBtn(bathVoyerActs action);
    void makePeekActBtn(peekActs action);
    QString bathStr(int value);
    QString bathActStr(int value);
    QString voyerStr(int value);
    QString voyerActStr(int value);
    QString peekStr(int value);
    QString peekActStr(int value);
    void shower();
    void noShampoo();
    void voyer();
//members
    int bath_lock;
    int no_bath;
    int skinday;
//temp variables
    int my_house;
    int remvanr;
    int family_trip;
    int stiralka;
    int husband;
    int husbandday;
    int poroshok;
    int husporday;
    int father_dadqw_day;
    int brother_ev1;
    QString brother_location;
    int brotherpeekstage;
    int brotherpeekhelp;
    int npc_39relation;
};

#endif
