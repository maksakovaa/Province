#ifndef LOCATION_H
#define LOCATION_H

#include <QString>
#include <QPushButton>
#include <QLabel>
#include "../items/cloth.h"
#include "../player/enums.h"
#include "../events/eventenums.h"
#include "../events/questenums.h"
#include "../npc/npc.h"
#include "loc_enums.h"

class LocationHandler;
class LocButton;

class Location: public QObject
{
    Q_OBJECT
    friend LocationHandler;
public:
    Location(LocationHandler* ptr);
    virtual void show(QString arg = "") = 0;
    virtual LocId getLocId() = 0;
    virtual LocId getParId() = 0;
    virtual LocId getLocIn() = 0;
    virtual QString getLocName() = 0;
    virtual bool isParent() = 0;
protected:
    void rendImagePage();
    void rendVideoPage();
    void rendObjPage();
    void addLayoutInObjPage(QLayout* layout);
    void setImage(QString path);
    void setVideo(QString path, int width, int height);
    void setDesc(QString text);
    void addText(QString text);
    void addActBtn(QPushButton* btn);
    void addLocBtn(LocButton* btn);
    void clearActions();
    void updateParams();
    void sendNotif(QString message);

    void fancywork();
    void home_workout();

    void drinkAll();
    void cookies();
    void fatDel();
    void vitamin();
    void pills();
    void eat(QString foodtype = "", QString image = "", QString text = "");
    void drink(QString napitokType);
    void fnAlko(int val);

    int getWeekNum();
    int getHour();
    int getMin();
    int getDay();
    int getMonth();
    int getSunWeather();
    int getSnow();
    int getTemp();
    int getSunrise();
    int getSunset();

    int cardCheck();
    void cardInit(int count, int time);
    QString getCard();
    int getCardTime();
    int getCardHorny();

    int gVStatus(Status param);
    int gVSick(Sickness param);
    int gVBody(Body param);
    int gVSex(SexVar param);
    int gVSkill(Skills param);
    int getItemCount(Items id);
    int gVSC(SC param);
    int gVJob(JobStatus param);
    int gVAddict(Addiction param);
    bool isAutoTampon();
    bool isDay();
    void incTime(int min);

    void uVStatus(Status param,int val);
    void uVBody(Body param, int val);
    void uVSC(SC param, int val);
    void uVSkill(Skills param,int val);
    void uVJob(JobStatus param, int val);
    void uVEvent(EventParams param, int val);
    void uVSex(SexVar param,int val);

    void sVStatus(Status param, int val);
    void sVBody(Body param, int val);
    void sVSex(SexVar param, int val);
    void sVJob(JobStatus param, int val);

    void updSkin(char c, int val);
    void setBoyName(QString name);

    void decrease_condition(int val = 1);
    void redress(ClothType type, Cloth* newCloth);
    void redressOld();
    void storeOldToWardrobe();
    void addCloth(Cloth* thing);
    int getClothGroup();
    Cloth* getCloth(ClothType type);
    bool isSkirt();
    bool isPanties();
    bool isGlamour();
    bool isJeans();
    bool isNude();
    bool isCloth();

    void useItem(Items id, int count);
    void addItem(Items id, int count);
    QString sextToysBlock(int val);
    QString getItemName(Items id);

    //beach acts
    void walk();
    void undress(int arg = 0);
    void sunbathe(int isCream = 0);
    void cream();
    void swim();
    void getDressed(int arg = 0);

    QString getPFName();

    Location* getLocPtr(LocId locId);

    int gVSchool(SchoolVar param);
    void uVSchool(SchoolVar param, int val);
    void sVSchool(SchoolVar param, int val);
    void startEvent(QString event, QString arg = "");
    int gVEvent(EventParams param);
    void sVEvent(EventParams param, int val);
    bool isHanters();
    int gVQuest(QuestParams param);
    void sVQuest(QuestParams param, int val);
    void uVQuest(QuestParams param, int val);
    void changeLoc(LocId locId, int min);
    void viewObj(QString object);
    void startSelfPlay();
    void fnSport(int arg = 0);

    void fnBlowJob();
    void fnCum(QString target);
    void fnSwallow();
    LocId getPrevId();
    LocId getPrevIn();
    QLabel* getTextPtr();

    NPC gNPC(int id);
private:
    virtual void actionHandler(QString action) = 0;
private:
    LocationHandler* root;
};

#endif // LOCATION_H
