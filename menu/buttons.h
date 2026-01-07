#ifndef QACTBUTTON_H
#define QACTBUTTON_H

#include <QPushButton>
#include "../nav/loc_enums.h"

class QActButton: public QPushButton
{
    Q_OBJECT
public:
    QActButton(QString action);
signals:
    void sigAct(QString act);
private:
    void clickHandle();
    QString m_action;
};

class LocButton: public QPushButton
{
    Q_OBJECT
public:
    LocButton(LocId locId, int min = 1);
signals:
    void sigChangeLoc(LocId locId, int time);
private slots:
    void slotClick();
private:
    LocId m_locId;
    int m_time;
};

class ObjButton: public QPushButton
{
    Q_OBJECT
public:
    ObjButton(QString objectName);
signals:
    void sigViewObject(QString obj);
private slots:
    void slotClick();
private:
    QString m_objName;
};

#endif // QACTBUTTON_H
