#include "questHandler.h"
#include "locationform.h"
#include "ui_locationform.h"

#include <QObject>
#include "../Functions.h"
#include <iostream>
QuestHandler::QuestHandler(LocationForm* ptr): root(ptr)
{
    initQuests();
}

bool QuestHandler::isQuest(QString locName)
{
    if(locdep[locName] != nullptr)
        return true;
    else
        return false;
}

void QuestHandler::runQuests(QString locName)
{
    // std::cout << "run quest in ques handler" << std::endl;
    locdep[locName]->start();
}

void QuestHandler::changeLoc(QString locId)
{
    root->slotOnChangeLocation(locId,0);
}

void QuestHandler::incTime(int min)
{
    root->incTime(min);
}

void QuestHandler::initQuests()
{
    PiratQuest* quest = new PiratQuest(this);
    locdep["sarai"] = quest;
}

void QuestHandler::addDesc(QString txt)
{
    root->addDesc(txt);
}

void QuestHandler::setDesc(QString txt)
{
    root->setDesc(txt);
}

void QuestHandler::setImage(QString txt)
{
    root->setImage(txt);
}

void QuestHandler::makeActBtn(Quest *ptr, QString act, QString actName)
{
    QuestActBtn* btn = new QuestActBtn(act);
    btn->setText(actName);
    connect(btn, &QuestActBtn::sigQuestAct, ptr, &Quest::slotActHandler);
    root->m_actLayout->addWidget(btn);
}

void QuestHandler::clearLayout()
{
    ClearLayout(root->m_actLayout);
}

int QuestHandler::getVStatus(Status type)
{
    return root->getVStatus(type);
}

int QuestHandler::getVSkill(Skills type)
{
    return root->getVSkill(type);
}

int QuestHandler::getVBody(Body param)
{
    return root->getVBody(param);
}

int QuestHandler::getDay()
{
    return root->getDay();
}

int QuestHandler::getVSex(SexVar type)
{
    return root->getSexVar(type);
}

void QuestHandler::setVBody(Body param, int val)
{
    root->setVBody(param, val);
}

void QuestHandler::setVSex(SexVar param, int val)
{
    root->setSexVar(param, val);
}

void QuestHandler::setVStatus(Status param, int val)
{
    root->setVStatus(param, val);
}

void QuestHandler::updVSkill(Skills type, int value)
{
    root->updVSkill(type, value);
}

void QuestHandler::updVStatus(Status type, int value)
{
    root->updVStatus(type, value);
}

void QuestHandler::updVBody(Body param, int val)
{
    root->updVBody(param, val);
}

void QuestHandler::updVStatistic(SC param, int val)
{
    root->updVStatistic(param,val);
}

void QuestHandler::updVSex(SexVar param, int val)
{
    root->updVSex(param,val);
}

void QuestHandler::setVideo(QString url, int width, int height)
{
    root->videoWidg->setQUrl(url, weight, height);
}

void QuestHandler::setVideoDesc(QString txt)
{
    root->setVideoDesc(txt);
}

void QuestHandler::addVideoDesc(QString txt)
{
    root->addVideoDesc(txt);
}

void QuestHandler::switchImageVideo(QString type)
{
    if(type == "video")
    {
        root->ui->imageAndWideoWdgt->setCurrentIndex(1);
    }
    if(type == "image")
    {
        root->ui->imageAndWideoWdgt->setCurrentIndex(0);
    }
}

Cloth *QuestHandler::getCloth(ClothType type)
{
    return root->getCloth(type);
}

bool QuestHandler::isSkirt()
{
    ClothMain* ptr = (ClothMain*)getCloth(ClothType::Main);
    if(ptr->getClothGroup() >= ClothGroup::skirt || ptr->getId() == 3 || ptr->getId() == 4)
        return true;
    else
        return false;
}

bool QuestHandler::isPanties()
{
    if(getCloth(ClothType::Panties) == nullptr)
        return false;
    else
        return true;
}
