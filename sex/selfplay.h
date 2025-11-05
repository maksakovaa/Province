#ifndef SELFPLAY_H
#define SELFPLAY_H

#include "sexviewform.h"

class SexViewForm;

enum SelfPlayActs
{
    actSP0, actSP1, actSP2, actSP3, actSP4, actSP5, actSP6, actSP7, actSP8, actSP9, actSP10, actSP11, actSP12, actSP13, actSP14, actSP15,
    actSP16, actSP17, actSP18, actSP19, actSP20, actSP21, actSP22, actSP23, actSP24, actSP25, actSP26
};

enum SelfPlayDesc
{
    descSP1, descSP2, descSP3, descSP4, descSP5, descSP6, descSP7, descSP8, descSP9, descSP10, descSP11, descSP12, descSP13,
    descSP14, descSP15, descSP16, descSP17, descSP18, descSP19, descSP20, descSP21, descSP22, descSP23, descSP24, descSP25,
    descSP26, descSP27, descSP28, descSP29, descSP30, descSP31, descSP32, descSP33, descSP34, descSP35, descSP36, descSP37,
    descSP38, descSP39, descSP40, descSP41, descSP42, descSP43, descSP44, descSP45, descSP46, descSP47, descSP48, descSP49,
    descSP50, descSP51, descSP52, descSP53, descSP54, descSP55, descSP56, descSP57, descSP58, descSP59
};


class SexActionButton: public QPushButton
{
    Q_OBJECT
public:
    SexActionButton(SelfPlayActs act, QString actName);
signals:
    void sigAction(SelfPlayActs act);
private:
    SelfPlayActs m_action;
private slots:
    void handleButtonClick();
};


class SelfPlay: public QObject
{
    Q_OBJECT
public:
    SelfPlay(QWidget* parent);
    void start();
public slots:
    void reloadActions();
private slots:
    void slotActionHandler(SelfPlayActs act);
private:
    Location* getCurLoc();
    void makeButtons();
    void makeActBtn(SelfPlayActs act);
    void incTime(int min);
    void updVSexVar(SexVar var, int count);
    int getVSexVar(SexVar var);
    void bathInvasion();
    void selfPlayEnding();
    int getVStatus(Status param);
    int getVBody(Body param);
    void updVStatus(Status param, int value);
    void setVStatus(Status param, int value);
    void setVSexVar(SexVar param, int value);
    void setImg(QString text);
    void setDesc(QString text);
    void appendDesc(QString text);
    int m_vagTemp{0};
    int getItemCount(Items i);
    QString getActName(SelfPlayActs act);
    QString getActDesc(SelfPlayDesc desc);
    SexViewForm* root;
    int m_dildohand;
    SelfPlayActs current;
};

#endif