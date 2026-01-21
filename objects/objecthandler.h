#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H

#include <QWidget>
#include <QVBoxLayout>
#include "../render.h"
#include "../player/player.h"
#include "../items/cloth.h"
#include "../locations/location.h"

class Mirror;
class Bed;
class Wardrobe;
class Books;

class ObjectHandler: public QObject
{
    Q_OBJECT
    friend Mirror; friend Bed; friend Wardrobe; friend Books; friend SaveForm; friend LoadForm;
public:
    ObjectHandler(Render* ptr, QWidget* parent = nullptr, QVBoxLayout* actions = nullptr);
    Cloth* wearCloth(Cloth* thing);
    void storeCloth(Cloth* thing, int count = 1);
    void removeCloth(ClothGroup group);
    void sleep();
    QString getBookName(int id);
    void readOnWalk();
    int eroReaded();
    void eroBlock();
public slots:
    void slotViewObj(QString objName);
    void slotInitWardrobe();
private:
    int getTemp();
    int getSunWeather();
    bool isNude();
    int getVStatus(Status param);
    int getVBody(Body param);
    int getVAddict(Addiction param);
    int getVBuzzer(budilnik param);
    int getVSick(Sickness param);
    int getHour();
    int getMin();
    int getMonth();
    int getVSC(SC param);
    int getVsexVar(SexVar param);
    int getItmCount(Items id);
    int alkoBlock();
    int gVQuest(QuestParams param);
    int gVEvent(EventParams param);
    void uVEvent(EventParams param,int val);
    void sVEvent(EventParams param, int val);
    void sVQuest(QuestParams param, int val);
    void sendNotif(QString text);
    void updateParams();
    void setVStatus(Status param, int val);
    void setVSexVar(SexVar param, int val);
    void setVBody(Body param, int val);
    void updVStatus(Status param, int val);
    void updVSkill(Skills param, int val);
    void updVBody(Body param, int value);
    void updBuzzer(budilnik param, int val);
    void updVAddict(Addiction param, int val);
    void incTime(int min);
    void changeLoc(LocId locId);
    void decreaseClothCond(int val = 1);
    void redress(ClothType type, Cloth* thing);
    void redressOld();
    void startSelfPlay();
    void useItem(Items id, int count);
    bool isPanties();
    bool isHapri();
    Cloth* getCloth(ClothType type);
    Location* getCurLoc();
    Player* player();
    NPC& gNPC(int id);
private:
    QWidget* root;
    Render* m_render;
    QVBoxLayout* m_actions;
    Mirror* m_mirror;
    Bed* m_bed;
    Wardrobe* m_wardrobe;
    Books* m_books;
};

#endif // OBJECTHANDLER_H
