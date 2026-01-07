#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H

#include <QWidget>
#include <QVBoxLayout>
#include "../render.h"
#include "../player/player.h"
#include "../items/cloth.h"
#include "../nav/location.h"

class Mirror;
class Bed;
class Wardrobe;

class ObjectHandler: public QObject
{
    Q_OBJECT
    friend Mirror; friend Bed; friend Wardrobe;
public:
    ObjectHandler(Render* ptr, QWidget* parent = nullptr, QVBoxLayout* actions = nullptr);
    Cloth* wearCloth(Cloth* thing);
    void storeCloth(Cloth* thing, int count = 1);
    void sleep();
public slots:
    void slotViewObj(QString objName);
    void slotInitWardrobe();
private:
    int getVStatus(Status param);
    int getVBody(Body param);
    int getVAddict(Addiction param);
    int getVBuzzer(budilnik param);
    int getVSick(Sickness param);
    int getHour();
    int getMin();
    int getVSC(SC param);
    int getVsexVar(SexVar param);
    int getItmCount(Items id);
    void updateParams();
    void setVStatus(Status param, int val);
    void setVSexVar(SexVar param, int val);
    void setVBody(Body param, int val);
    void updVStatus(Status param, int val);
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
private:
    QWidget* root;
    Render* m_render;
    QVBoxLayout* m_actions;
    Mirror* m_mirror;
    Bed* m_bed;
    Wardrobe* m_wardrobe;
};

#endif // OBJECTHANDLER_H
