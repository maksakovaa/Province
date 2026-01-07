#include "meadow.h"
#include "../menu/qactbutton.h"
#include "../Functions.h"

Meadow::Meadow(LocationHandler* ptr): Location(ptr) {}

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
        setImage(media(0));
        setDesc(str(0));
        if(gVEvent(mirainmeadow) == 1)
        {
            addText(str(1));
        }
        if(gVEvent(meadow) == 3 && gVEvent(mirainmeadow) == 0)
        {
            int tmp = getRandInt(0,9);
            if(gVEvent(Mira_no) == 0 && gVEvent(mirainmeadow) == 0 && getTemp() >= 20 && getSunWeather() >= 0)
            {
                QString string;
                if(gVEvent(mirasextimes) < 15 && tmp == 1)
                    string = str(2);
                if(gVQuest(miragopQW) >= 2 && tmp == 1)
                    string = str(3);
                if(gVQuest(miragopQW) >= 8 && tmp == 2)
                    string = str(3);
                if(gVQuest(miragopQW) >= 11 && tmp == 3)
                    string = str(4);
                if(gVQuest(miragopQW) >= 11 && tmp == 4)
                    string = str(5);
                if(gVQuest(miragopQW) >= 11 && tmp == 5)
                    string = str(5);
                if(gVQuest(miragopQW) >= 11 && tmp == 6)
                    string = str(6);
                if(gVQuest(miragopQW) >= 20 && tmp == 7)
                    string = str(7);
                if(gVQuest(miragopQW) >= 33 && tmp == 8)
                    string = str(8);
                if(gVQuest(miragopQW) >= 20 && tmp == 9)
                    string = str(2);
                if(!string.isEmpty())
                    addText(str(9) + string + str(10));
            }
        }
        makeActBtn("to_gaddvor",act(0));
        int miratemp = getRandInt(1,5);
        if(gVEvent(meadow) == 3 && gVEvent(mirainmeadow) == 0 && gVQuest(miragopQW) == 2 && getTemp() >= 15 && getSunWeather() >= 0)
            startEvent("Meadow_event","mira_mitka");
        if(gVEvent(meadow) == 3 && gVEvent(Mira_no) == 0 && gVEvent(mirainmeadow) == 0 && gVQuest(miragopQW) == 33 && getTemp() >= 15 && getSunWeather() >= 0)
            startEvent("Meadow_event", "mira_gang");
        if(gVEvent(mitkasextimes) > 13 && gVEvent(mirasex) == 0 && gVQuest(miragopQW) < 11)
            startEvent("Meadow_event", "mira_lesb_talk1");
        if(gVEvent(mitkasextimes) > 13 && gVEvent(mirasex) == 1 && gVQuest(miragopQW) < 11 && miratemp == 1 && gVEvent(miraday) != getDay())
            startEvent("Meadow_event", "mira_lesb_talk3");
        if(gVEvent(mitkasextimes) > 13 && gVEvent(mirasex) == 1 && gVQuest(miragopQW) > 11 && gVEvent(lickmira) == 0)
            startEvent("Meadow_event", "mira_lesb_talk2");
        if(gVEvent(mirasex) == 2 && miratemp > 3 && gVEvent(miraday) != getDay() && gVQuest(miraQW) >= 15)
            startEvent("Meadow_event", "mira_lesb");
    }
    if(action == "to_gaddvor")
    {
        sVEvent(mirainmeadow,0);
        changeLoc(lgaddvor,30);
    }
    if(action == "mirameadow")
    {
        startEvent("Meadow_event","mirameadow");
    }
    if(action == "Miroslava")
    {
        startEvent("Miroslava");
    }
}

void Meadow::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Meadow::actionHandler);
    addActBtn(btn);
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
