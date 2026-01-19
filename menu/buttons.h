#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include "../locations/loc_enums.h"
#include "../objects/objenums.h"
#include "../locations/common/bathenums.h"

class SaveForm;
class QActButton: public QPushButton
{
    Q_OBJECT
    friend SaveForm;
public:
    QActButton(QString action,QString handler);
signals:
    void sigAct(QString act);
private:
    void clickHandle();
    QString m_action;
    QString m_handler;
};

class BedActionButton: public QPushButton
{
    Q_OBJECT
public:
    BedActionButton(QString actName, BedActs act);
signals:
    void sigAction(BedActs act);
private:
    BedActs m_action;
private slots:
    void handleButtonClick();
};

class MirrActionButton: public QPushButton
{
    Q_OBJECT
public:
    MirrActionButton(QString actName, MirrorActs act);
signals:
    void sigAction(MirrorActs act);
private:
    MirrorActs m_action;
private slots:
    void handleButtonClick();
};

class WardrActionButton: public QPushButton
{
    Q_OBJECT
public:
    WardrActionButton(QString actName, WardrActs act);
signals:
    void sigAction(WardrActs act);
private:
    WardrActs m_action;
private slots:
    void handleButtonClick();
};

class BathActBtn: public QPushButton
{
    Q_OBJECT
public:
    BathActBtn(bathActs act, QString actName);
signals:
    void sigAction(bathActs act);
private:
    bathActs m_action;
private slots:
    void handleButtonClick();
};

class SaveBtn: public QPushButton
{
    Q_OBJECT
public:
    SaveBtn(QString file);
signals:
    void sigSaveClick(QString file);
private slots:
    void slotClick();
private:
    QString m_file;
};

#endif // BUTTONS_H
