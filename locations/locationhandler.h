#ifndef LOCATIONHANDLER_H
#define LOCATIONHANDLER_H

#include "location.h"
#include "../render.h"
#include <QPushButton>
#include "../events/eventhandler.h"
#include "common/common_headers.h"

class Player;
class SexHandler;

class LocationHandler: public QObject
{
    Q_OBJECT
    friend Location; friend EventHandler; friend KitchenActs;
    friend Common; friend Beach; friend Player;
    friend SaveForm; friend LoadForm; friend SexHandler;
public:
    LocationHandler(Game *parent);
    LocId getCurLoc();
    LocId getMainLoc();
    LocId getPrevLoc();
    Location* getCurPtr();
    void checkMapAwailable();
    Location* getLocPtr(LocId locId);
//Common
    void icecream();
    void coffee();
    void read_porn();
    void crossing(int arg);
    void home_workout();
    void lokerchoice();
    void sitrobrd();
    void sitrskakd();
    void sitrpressd();
    void sitrpushd();
    void watch_tv_on_sofa();
    void run_competition(QString arg);
    void fancywork();
    bool check_inhome();
    void wet_wipes();
    int getClothDecreaseLevel();
    void fnsport(int arg = 0);
    void waiting(int arg = 0);
//Cards
    void init(int count, int min);
    int check();
    int getCardTime();
    int getCardHorny();
    QString getCard();
//beach acts
    void walk();
    void undress(int arg = 0);
    void sunbathe(int isCream = 0);
    void cream();
    void swim();
    void getDressed(int arg = 0);
//Kitchen acts
    void kitchenActsAll(int arg);
    void drinkAll();
    void cookies();
    void fatDel();
    void vitamin();
    void pills();
    void eat(QString foodtype = "", QString image = "", QString text = "");
    void drink(QString napitokType);
public slots:
    void slotChangeLoc(LocId id, int time, QString arg = "");
signals:
    void sigUpdParams();
private: //Methods
    void genLocations();
private: //Access methods
    void updateParams();
private: //Members
    Location* m_current;
    Location* m_prev;
    Game* root;
    Card m_card;
    std::unordered_map<LocId,Location*> m_locations;
    KitchenActs* m_kitchenActs;
    Common* m_common;
    Beach* m_beach;
};

#endif // LOCATIONHANDLER_H
