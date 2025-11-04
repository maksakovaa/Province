#ifndef OBJVIEWFORM_H
#define OBJVIEWFORM_H

#include "location.h"
#include <QPushButton>
#include <QWidget>
#include <qstackedwidget.h>
#include "cloth.h"
#include "player.h"
#include "../video.h"
#include "clothform.h"
#include "clothformTrash.h"

namespace Ui {
class ObjViewForm;
}

class ObjActionButton: public QPushButton
{
    Q_OBJECT
public:
    ObjActionButton(QString actName);
signals:
    void sigAction(QString name);
private:
    QString m_actionName;
private slots:
    void handleButtonClick();
};

class Mirror;
class Bed;
class Wardrobe;

class ObjViewForm : public QWidget
{
    Q_OBJECT
    friend Mirror;
    friend Bed;
    friend Wardrobe;
signals:
    void sigSpendTime(int min);
    void sigUpdParams();
public:
    explicit ObjViewForm(QWidget *parent = nullptr);
    ~ObjViewForm();
    void setActLayoutPtr(QVBoxLayout* ptr);
    void storeCloth(Cloth* thing, int count = 1);
    Cloth* wearCloth(Cloth* thing);
public slots:
    void slotViewObj(QString objName);
    void slotInitWardrobe();
private:
    int getVStatus(Status type);
    int getVBody(Body type);
    int getVsexVar(SexVar type);
    int getVAddict(Addiction type);
    int getVSick(Sickness type);
    int getItmCount(Items type);
    int getVBuzzer(budilnik type);
    int getHour();
    int getMin();
    int getVSC(SC param);
    void useItem(Items type, int count);
    void setVStatus(Status type, int value);
    void setVSexVar(SexVar type, int value);
    void setVBody(Body param, int val);
    void updVStatus(Status type, int value);
    void updVAddict(Addiction type, int val);
    void updVBody(Body param, int val);
    void redress(Cloth* newCloth);
    void incTime(int min);
    void decreaseClothCond();
    void updBuzzer(budilnik type, int val);
    Cloth* getCloth(ClothType type);
    bool isPanties();
    Location* getCurLoc();
    void changeLoc(Location* newLoc, int min);
    void startSelfPlay(Location* loc);
    Player* player();
    bool isHapri();
//members
    Ui::ObjViewForm *ui;
    QWidget* root;
    QVBoxLayout* m_actLayout;
    Mirror* m_mirror;
    Bed* m_bed;
    Wardrobe* m_wardrobe;
    Video* videoWidg;
};

#endif // OBJVIEWFORM_H
