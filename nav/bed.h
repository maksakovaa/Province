#ifndef BED_H
#define BED_H

#include "objviewform.h"
#include "GameObj.h"

enum BedActs
{
    actBed0, actBed1, actBed2, actBed3, actBed4, actBed5, actBed6, actBed7, actBed8, actBed9, actBed10, actBed11
};

class BedActionButton: public QPushButton
{
    Q_OBJECT
public:
    BedActionButton(QString actName, BedActs act): m_action(act) 
    { this->setText(actName); this->setCursor(Qt::PointingHandCursor);
    connect(this, &BedActionButton::clicked, this, &BedActionButton::handleButtonClick); }
signals:
    void sigAction(BedActs act);
private:
    BedActs m_action;
private slots:
    void handleButtonClick() { emit sigAction(m_action); }
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
public slots:
    void reloadActions();
private slots:
    void slotActHandler(BedActs act);
    void on_labelObjImage_linkActivated(const QString &link);
    void on_labelObjDesc_linkActivated(const QString &link);
private:
    QString str(BedActs act);
    QString actStr(BedActs act);
    void makeButtons();
    void makeBedActBtn(BedActs act);
    void sleepInBed();
    void relaxInBed();
    void bedDreams();
    ObjViewForm* root;
    QString m_name;
    QString m_desc;
    Cloth* old_cloth;
    Cloth* old_panties;
    Cloth* old_stockings;
    BedActs current;
};

#endif