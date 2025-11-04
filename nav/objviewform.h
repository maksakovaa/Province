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

class GameObj: public QObject
{
    Q_OBJECT
public:
    GameObj(){};
    virtual ~GameObj(){};
    virtual QString getName() = 0;
    virtual QString getImage() = 0;
    virtual QString getDesc() = 0;
};

class Mirror: public GameObj
{
    Q_OBJECT
public:
    Mirror(QWidget* ptr);
    ~Mirror();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    void viewMirror();
private slots:
    void slotMirrorActHandler(QString actName);
private:
    void makeMirrorActBtn(QString text);
    void makeBackBtn(QString text);
    ObjViewForm* root;
    QString m_name;
    QString m_desc;
};

class Bed: public GameObj
{
    Q_OBJECT
public:
    Bed(QWidget* ptr);
    ~Bed();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    QString getDreamsDesc(int i);
    QString getDreamsAfter(int i);
    void viewBed();
private slots:
    void slotBedActHandler(QString actName);
    void on_labelObjImage_linkActivated(const QString &link);
    void on_labelObjDesc_linkActivated(const QString &link);
private:
    void makeBackBtn(QString text);
    void makeBedActBtn(QString text);
    void sleepInBed();
    void relaxInBed();
    void selfPlay();
    void budilnik();
    void bedDreams();
    ObjViewForm* root;
    QString m_name;
    QString m_desc;
    Cloth* old_cloth;
    Cloth* old_panties;
    Cloth* old_stockings;
};

class Wardrobe: public GameObj
{
    Q_OBJECT
    friend void ObjViewForm::slotInitWardrobe();
public:
    Wardrobe(QWidget* ptr);
    ~Wardrobe() = default;
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    void viewWardrobe();
    void trashBox();
    void addCloth(Cloth* thing, int count);
    Cloth* wearCloth(Cloth* thing);
public slots:
    void slotUpdSize(int size);
private slots:
    void wardrobeHandler(QString act);
    void clothFormHandler(Cloth* cloth, QString action);
    void clotTrashHandler(Cloth* cloth, QString action);
private:
    ClothForm* genForm(ClothMain* cloth);
    ClothFormTrash* genTrashForm(ClothMain* cloth);
    void initNewLayout();
    void initWarDrobe();
    void finalize();
    int countPanties();
    void makeActBtn(QString txt);
    QString warStr(int index);
    ObjViewForm* root;
    ClothPanties* m_panties;
    std::unordered_map<Cloth*, int> m_storage;
    std::vector<Cloth*> m_trash;
    std::vector<QHBoxLayout*> m_layouts;
    int m_size;
};

#endif // OBJVIEWFORM_H
