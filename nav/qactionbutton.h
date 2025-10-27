#ifndef QACTIONBUTTON_H
#define QACTIONBUTTON_H
#include <QObject>
#include <QPushButton>
#include "location.h"

class QActionButton: public QPushButton
{
    Q_OBJECT
public:
    QActionButton(int time = 0);
    void setLocPtr(Location* ptr);
    void setObjName(QString name);
    void setActName(QString name);
signals:
    void sigChangeSubLoc(Location* ptr, int min);
    void sigViewObj(QString name);
    void sigMakeAct(Location* loc, QString action);
private slots:
    void handleButtonClick();
private:
    int m_time;
    Location* m_loc;
    QString m_obj;
    QString m_act;
};

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

#endif // QACTIONBUTTON_H
