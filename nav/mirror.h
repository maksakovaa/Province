#ifndef MIRROR_H
#define MIRROR_H

#include "GameObj.h"
#include "objviewform.h"

enum MirrorActs
{
    actMirr0, actMirr1, actMirr2, actMirr3, actMirr4, actMirr5, actMirr6, actMirr7, actMirr8, actMirr9
};

class MirrActionButton: public QPushButton
{
    Q_OBJECT
public:
    MirrActionButton(QString actName, MirrorActs act): m_action(act) 
    { this->setText(actName); this->setCursor(Qt::PointingHandCursor);
    connect(this, &MirrActionButton::clicked, this, &MirrActionButton::handleButtonClick); }
signals:
    void sigAction(MirrorActs act);
private:
    MirrorActs m_action;
private slots:
    void handleButtonClick() { emit sigAction(m_action); }
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
public slots:
    void reloadActions();
private slots:
    void slotMirrorActHandler(MirrorActs act);
private:
    void makeButtons();
    void makeMirrorActBtn(MirrorActs act);
    QString actStr(MirrorActs type);
    QString str(MirrorActs type);
    ObjViewForm* root;
    QString m_name;
    QString m_desc;
    MirrorActs current;
};

#endif