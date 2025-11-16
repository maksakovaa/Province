#ifndef QUESTHANDLER_H
#define QUESTHANDLER_H

#include <QString>
#include <unordered_map>
#include <QHash>
#include <QPushButton>
#include "../Quests/quest.h"
#include "../Quests/gadukino/pirat.h"
#include "../player/enums.h"
#include "cloth.h"
#include <iostream>

class LocationForm;

class QuestActBtn: public QPushButton
{
    Q_OBJECT
public:
    QuestActBtn(QString act): m_act(act)
    {
        this->setCursor(Qt::PointingHandCursor);
        connect(this, &QuestActBtn::clicked, this, &QuestActBtn::handler);
    }
signals:
    void sigQuestAct(QString act);
private slots:
    void handler()
    {
        std::cout << m_act.toStdString() << std::endl;
        emit sigQuestAct(m_act);
    }
private:
    QString m_act;
};

class QuestHandler: public QObject
{
    Q_OBJECT
    friend PiratQuest;
public:
    QuestHandler(LocationForm* ptr);
    bool isQuest(QString locName);
    void runQuests(QString locName);
private:
    void changeLoc(QString locId);
    void incTime(int min);
    void initQuests();
    void addDesc(QString txt);
    void setDesc(QString txt);
    void setImage(QString txt);
    void makeActBtn(Quest* ptr, QString act, QString actName);
    void clearLayout();
    int getVStatus(Status type);
    int getVSkill(Skills type);
    int getVBody(Body param);
    int getDay();
    int getVSex(SexVar type);
    void setVBody(Body param, int val);
    void setVSex(SexVar param, int val);
    void setVStatus(Status param, int val);
    void updVSkill(Skills type, int value);
    void updVStatus(Status type, int value);
    void updVBody(Body param, int val);
    void updVStatistic(SC param, int val);
    void updVSex(SexVar param, int val);
    void setVideo(QString url, int width, int height);
    void setVideoDesc(QString txt);
    void addVideoDesc(QString txt);
    void switchImageVideo(QString type);
    Cloth* getCloth(ClothType type);
    bool isSkirt();
    bool isPanties();
    std::unordered_map<QString, Quest*> locdep;
    LocationForm* root;
};

#endif
