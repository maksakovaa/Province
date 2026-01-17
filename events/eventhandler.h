#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QWidget>
#include "questenums.h"
#include "../player/enums.h"
#include "event.h"
#include "eventenums.h"
#include "items/cloth.h"
#include <QLabel>
#include <QPushButton>
#include "../nav/location.h"

class LocationHandler;
class SaveForm; class LoadForm;

class EventHandler
{
    friend SaveForm; friend LoadForm;
public:
    EventHandler(LocationHandler* ptr);
    void eventStart(QString event, QString args = 0);
    void rendImagePage();
    void rendVideoPage();
    void setImage(QString path);
    void setVideo(QString path, int width, int height);
    void setDesc(QString text);
    void addDesc(QString text);
    void addActBtn(QPushButton* btn);
    void clearActions();
    QLabel* getTextPtr();
    void eat(QString foodtype = "", QString image = "", QString text = "");

    int getAge();
    int getMonth();
    int getSunWeather();
    int getSunset();
    int getSunrise();
    int getDay();
    bool isDay();
    int getHour();
    int getWeekNum();
    int getTemp();
    int getSnow();

    int getItmCount(Items id);
    void addItem(Items id, int count);
    void useItem(Items id, int count);

    int vStatus(Status param);
    int vBody(Body param);
    int vSkill(Skills param);
    int vSC(SC param);
    int vAddict(Addiction param);
    int vSex(SexVar param);
    int vSick(Sickness param);

    bool isMesec();

    void uVStatus(Status param,int val);
    void uVBody(Body param, int val);
    void uVSkill(Skills param,int val);
    void uVSC(SC param,int val);
    void uVSex(SexVar param,int val);

    void sVStatus(Status param,int val);
    void sVSex(SexVar param,int val);
    void sVBody(Body param, int val);
    void setBoyName(QString name);
    void setBoy2Name(QString name);
    void fnAlko(int val);
    QString getLipTalk();
    QString getLipTalk3();
    QString getAnusTipe();
    QString getAnusTipe2();
    QString getVaginaTipe2();
    QString getBoyName();
    QString getBoy2Name();

    Cloth* getCloth(ClothType type);
    void redress(ClothType type, Cloth* newCloth);
    void redressOld();
    bool isNude();
    bool isCloth();
    bool isSkirt();
    bool isPanties();
    int getClothGroup();
    void decCondition(int val = 1);

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

    void changeLoc(LocId locId, int min = 0, QString arg = "");
    LocId getCurLoc();
    Location* getLocPtr();
    Location* getLocPtr(LocId loc);
    NPC& gNPC(int id);
    void sleep();

    int gVSchool(SchoolVar param);
    void uVSchool(SchoolVar param,int val);
    void sVSchool(SchoolVar param, int val);
    int gVEvent(EventParams param);
    void sVEvent(EventParams param, int val);
    void uVEvent(EventParams param, int val);
    bool isHanters();
    int gVJob(JobStatus param);
    void sVJob(JobStatus param,int val);
    int gVQuest(QuestParams param);
    void sVQuest(QuestParams param, int val);
    void uVQuest(QuestParams param, int val);
    void incTime(int min);
private:
    void initEvents();
private:
    LocationHandler* root;
    std::unordered_map<QString,Event*> m_events;
    std::unordered_map<EventParams,int> m_eventval;
    std::unordered_map<QuestParams, int> m_questval;
    std::unordered_map<SchoolVar,int> m_schoolVal;
};

#endif // EVENTHANDLER_H
