#include "meadow.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"
#include "../../game.h"

Meadow::Meadow(Game* ptr): root(ptr) {}

void Meadow::show(QString arg)
{
    actionHandler("meadow");
}

LocId Meadow::getLocId()
{
    return lmeadow;
}

LocId Meadow::getLocIn()
{
    return lgadukino;
}

QString Meadow::getLocName()
{
    return "Поляна";
}

LocId Meadow::getParId()
{
    return lgaddvor;
}

bool Meadow::isParent()
{
    return true;
}

void Meadow::actionHandler(QString action)
{
    if(action == "meadow")
    {
        root->setImage(media(0));
        root->setText(str(0));
        if(root->vEvent(mirainmeadow) == 1)
        {
            root->addText(str(1));
        }
        if(root->vEvent(meadow) == 3 && root->vEvent(mirainmeadow) == 0)
        {
            int tmp = getRandInt(0,9);
            if(root->vEvent(Mira_no) == 0 && root->vEvent(mirainmeadow) == 0 && root->getTemp() >= 20 && root->getSunWeather() >= 0)
            {
                QString string;
                if(root->vEvent(mirasextimes) < 15 && tmp == 1)
                    string = str(2);
                if(root->vQuest(miragopQW) >= 2 && tmp == 1)
                    string = str(3);
                if(root->vQuest(miragopQW) >= 8 && tmp == 2)
                    string = str(3);
                if(root->vQuest(miragopQW) >= 11 && tmp == 3)
                    string = str(4);
                if(root->vQuest(miragopQW) >= 11 && tmp == 4)
                    string = str(5);
                if(root->vQuest(miragopQW) >= 11 && tmp == 5)
                    string = str(5);
                if(root->vQuest(miragopQW) >= 11 && tmp == 6)
                    string = str(6);
                if(root->vQuest(miragopQW) >= 20 && tmp == 7)
                    string = str(7);
                if(root->vQuest(miragopQW) >= 33 && tmp == 8)
                    string = str(8);
                if(root->vQuest(miragopQW) >= 20 && tmp == 9)
                    string = str(2);
                if(!string.isEmpty())
                    root->addText(str(9) + string + str(10));
            }
        }
        makeActBtn("to_gaddvor",act(0));
        int miratemp = getRandInt(1,5);
        if(root->vEvent(meadow) == 3 && root->vEvent(mirainmeadow) == 0 && root->vQuest(miragopQW) == 2 && root->getTemp() >= 15 && root->getSunWeather() >= 0)
            root->startEvent(eMeadowEvent,"mira_mitka");
        if(root->vEvent(meadow) == 3 && root->vEvent(Mira_no) == 0 && root->vEvent(mirainmeadow) == 0 && root->vQuest(miragopQW) == 33 && root->getTemp() >= 15 && root->getSunWeather() >= 0)
            root->startEvent(eMeadowEvent, "mira_gang");
        if(root->vEvent(mitkasextimes) > 13 && root->vEvent(mirasex) == 0 && root->vQuest(miragopQW) < 11)
            root->startEvent(eMeadowEvent, "mira_lesb_talk1");
        if(root->vEvent(mitkasextimes) > 13 && root->vEvent(mirasex) == 1 && root->vQuest(miragopQW) < 11 && miratemp == 1 && root->vEvent(miraday) != root->getDay())
            root->startEvent(eMeadowEvent, "mira_lesb_talk3");
        if(root->vEvent(mitkasextimes) > 13 && root->vEvent(mirasex) == 1 && root->vQuest(miragopQW) > 11 && root->vEvent(lickmira) == 0)
            root->startEvent(eMeadowEvent, "mira_lesb_talk2");
        if(root->vEvent(mirasex) == 2 && miratemp > 3 && root->vEvent(miraday) != root->getDay() && root->vQuest(miraQW) >= 15)
            root->startEvent(eMeadowEvent, "mira_lesb");
    }
    if(action == "to_gaddvor")
    {
        root->vEvent(mirainmeadow) = 0;
        root->changeLoc(lgaddvor,30);
    }
    if(action == "mirameadow")
    {
        root->startEvent(eMeadowEvent,"mirameadow");
    }
    if(action == "Miroslava")
    {
        root->startEvent(eMiroslava);
    }
}

void Meadow::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "meadow");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Meadow::actionHandler);
    root->addActions(btn);
}

QString Meadow::str(int id)
{
    QString str[11];
    str[0] = "Тихое заброшенное местечко, хорошо скрытое зелеными зарослями от цивилизации.";
    str[1] = "На поляне с восторгом кружится <a href='Miroslava'>Мира</a>.";
    str[2] = "Миру";
    str[3] = "Миру с Митькой";
    str[4] = "Миру с Колямбой";
    str[5] = "Миру с Васяном";
    str[6] = "Миру с Митькой,Васяном и Колямбой";
    str[7] = "Миру с Васяном и Колямбой";
    str[8] = "кучу деревенских полуголых мужиков";
    str[9] = "На поляне вы замечаете <a href='mirameadow'>";
    str[10] = "</a>.";
    return str[id];
}

QString Meadow::act(int id)
{
    QString act[1];
    act[0] = "Уйти";
    return act[id];
}

QString Meadow::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/gaddvor/meadow.jpg";
    return med[id];
}
