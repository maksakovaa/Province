#ifndef BED_H
#define BED_H

#include "GameObj.h"
#include "objecthandler.h"
#include "objenums.h"

class Bed: public GameObj
{
    Q_OBJECT
    friend ObjectHandler;
public:
    Bed(ObjectHandler* ptr);
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
    ObjectHandler* root;
    QString m_name;
    QString m_desc;
    BedActs current;
};

#endif
