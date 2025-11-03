#ifndef OBJVIEWFORM_H
#define OBJVIEWFORM_H

#include "location.h"
#include "locationform.h"
#include <QPushButton>
#include <QWidget>
#include <qstackedwidget.h>
#include "cloth.h"

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
    void setRoot(QWidget* ptr);
    // void setPlayerPtr(Player* ptr);
    void setActLayoutPtr(QVBoxLayout* ptr);
    // void setPagePtr(QStackedWidget* ptr);
    // void setSettingsPtr(Settings* ptr);
    // void setTimeServerPtr(TimeServer* ptr);
public slots:
    void slotViewObj(QString objName);
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
//members
    Ui::ObjViewForm *ui;
    QWidget* root;
    // Player* m_player;
    QVBoxLayout* m_actLayout;
    //QStackedWidget* m_page;
    // Settings* m_settings;
    // BagForm* m_bag;
    // TimeServer* m_time;
    //LocationForm* m_loc;
    Mirror* m_mirror;
    Bed* m_bed;
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
public:
    Wardrobe(QWidget* ptr);
    ~Wardrobe() = default;
    void addCloth(Cloth* thing);
    Cloth* wearCloth(Cloth* thing);
public slots:
    void slotUpdSize(int size);
private:
    ObjViewForm* root;
    std::unordered_map<Cloth*, int> m_storage;
    int m_size;
};

#endif // OBJVIEWFORM_H
