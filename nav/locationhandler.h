#ifndef LOCATIONHANDLER_H
#define LOCATIONHANDLER_H

#include "location.h"
#include "../render.h"
#include <QPushButton>
#include "../events/eventhandler.h"
#include "../common/common_headers.h"
#include "../npc/npc.h"

class Player;

class LocationHandler: public QObject
{
    Q_OBJECT
    friend Location; friend EventHandler; friend KitchenActs;
    friend Common; friend Beach; friend Player;
public:
    LocationHandler(Render* ptr, QWidget *parent, QVBoxLayout* actionsLayout);
    LocId getCurLoc();
    LocId getMainLoc();
    LocId getPrevLoc();
    Location* getCurPtr();
    int gVSchool(SchoolVar param);
    void uVSchool(SchoolVar param, int val);
    void sVSchool(SchoolVar param, int val);
public slots:
//    void slotChangeLoc(const QString& locId, int time, QString arg = "");
    void slotChangeLoc(LocId id, int time, QString arg = "");
signals:
    void sigUpdParams();
private: //Methods
    void genLocations();
private: //Access methods
    void updateParams();
    void incTime(int min);

    void updVBody(Body param, int val);
    void updVStatus(Status param, int val);
    void updVStatistic(SC param, int val);
    void updVSkill(Skills type, int val);
    void updVSex(SexVar param, int val);
    void updVSick(Sickness param, int val);
    void updVJob(JobStatus param, int val);
    void fnAlko(int val);
    void useItem(Items item, int count);

    void setSexVar(SexVar var, int value);
    void setVStatus(Status param, int value);
    void setVBody(Body param, int value);
    void setVJob(JobStatus param,int val);
    void setVSC(SC param,int val);
    void setBoyName(QString name);
    void setBoy2Name(QString name);

    void startSelfPlay();
    void sexStart();
    void analStart(ToolType type = tDick);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
    void sex_cum();
    void cum(QString target);
    void blow_job();
    void anal_cum();
    void fnswallow();
    void dp_start();
    void double_penetration();
    void sleepInBed();

    int getVBody(Body param);
    int getVStatus(Status param);
    int getItmCount(Items item);
    int getSexVar(SexVar var);
    int getVStatistic(SC param);
    int getVSkill(Skills type);
    int getVSick(Sickness param);
    int getVJob(JobStatus param);
    int getVAddict(Addiction param);

    QString getLipTalk();
    QString getLipTalk3();
    QString getAnusTipe2();
    QString getAnusTipe();
    QString getVaginaTipe2();
    QString getBoyName();
    QString getBoy2Name();
    QString getPFName();
    int getAge();
    int getDay();
    int getMonth();
    int getHour();
    int getMin();
    int getWeekNum();
    int getSunWeather();
    int getSnow();
    int getTemp();
    int getSunrise();
    int getSunset();

    void setImage(QString path);
    void setDesc(QString text);
    void addDesc(QString str);

    bool isAutoTampon();
    void redress(ClothType type, Cloth* newCloth);
    void redressOld();
    void storeOldToWardrobe();
    Cloth* getCloth(ClothType type);
    bool isSkirt();
    bool isPanties();
    bool isGlamour();
    bool isJeans();
    bool isNude();
    bool isCloth();
    int getClothGroup();
    void addCloth(Cloth* thing);
    void decreaseCondition(int val = 1);
    int getClothDecreaseLevel();

    void viewObj(QString obj);
    void updSkin(char c, int val);
    void addItem(Items id, int count = 1);
    bool isDay();
    void sendNotif(QString text);
    QString getItemName(Items id);
    QString sextToysBlock(int val);
    Location* getLocPtr(LocId locId);

    NPC &gNPC(int id);
private: //Members
    Location* m_current;
    Location* m_prev;
    Render* m_render;
    QWidget* m_root;
    QVBoxLayout* m_actions;
    Card m_card;
    std::unordered_map<LocId,Location*> m_locations;
    EventHandler* m_events;
    KitchenActs* m_kitchenActs;
    Common* m_common;
    Beach* m_beach;
};

#endif // LOCATIONHANDLER_H
