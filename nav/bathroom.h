#ifndef BATHROOM_H
#define BATHROOM_H

#include <QObject>
#include "locationform.h"

class LocationForm;

enum bathActs 
{
    actBath1, actBath2, actBath3, actBath4, actBath5, actBath6, actBath7, actBath8, actBath9, actBath10, actBath11, actBath12,
    actBath13, actBath14, actBath15, actBath16, actBath17, actBath18, actBath19, actBath20, actBath21, actBath22, actBath23, actBath24,
    actBath25, actBath26, actBath27, actBath28, actBath29, actBath30, actBath31, actBath32
};
enum bathVoyerActs
{
    actBV1, actBV2, actBV3, actBV4, actBV5, actBV6, actBV7, actBV8
};

enum peekActs
{
    actPeek1, actPeek2, actPeek3, actPeek4, actPeek5, actPeek6, actPeek7,
    actPeek8, actPeek9, actPeek10, actPeek11
};

class BathActBtn: public QPushButton
{
    Q_OBJECT
public:
    BathActBtn(bathActs act, QString actName);
signals:
    void sigAction(bathActs act);
private:
    bathActs m_action;
private slots:
    void handleButtonClick();
};

class BathRoom: public QObject
{
    Q_OBJECT
public:
    BathRoom(LocationForm* ptr);
    void start();
private slots:
    void slotBathActionHandler(bathActs action);
    void slotPeekActHandler(peekActs action);
    void slotVoyerActHandler(bathVoyerActs action);
private:
//methods
    void bathActions(std::vector<struct Action*> acts);
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
    void savePrevCloth();
    TimeServer* gTime();
    QString backLoc();
    void shower();
    void cleanMe();
    void noShampoo();
    void voyer();
    int week();
    int hour();
    int minut();
    int day();
//members
    LocationForm* root;
    int bath_lock;
    int no_bath;
    int skinday;
    ClothMain* prevCloth;
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