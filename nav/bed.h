#ifndef BED_H
#define BED_H

#include "objviewform.h"
#include "GameObj.h"

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

#endif