#include "gaddvor.h"
#include "../Functions.h"
#include "../events/questenums.h"
#include "../menu/buttons.h"
Gaddvor::Gaddvor(LocationHandler *ptr): Location(ptr) {}

void Gaddvor::show(QString arg)
{
    actionHandler("gaddvor");
}

LocId Gaddvor::getLocId()
{
    return lgaddvor;
}

LocId Gaddvor::getParId()
{
    return lgadukino;
}

LocId Gaddvor::getLocIn()
{
    return lgadukino;
}

QString Gaddvor::getLocName()
{
    return "Двор";
}

bool Gaddvor::isParent()
{
    return true;
}

void Gaddvor::actionHandler(QString action)
{
    if(action == "gaddvor")
    {
        sVEvent(grandpa_ingaddvor,0);
        setImage(makeImage(media(0), isDay(), getMonth()));
        setDesc(getStr(0));
        if(isDay() && getMonth() >= 4 && getMonth() <= 10)
            addText(getStr(1));
        if(gVEvent(mira_guest) == 1)
            addText(getStr(2));
        if(getMonth() > 5 && getMonth() < 9 && getSunWeather() >= 0 && gVJob(graze_cow) == 0)
        {
            if((getHour() > 7 && getHour() < 13  && (getWeekNum() == 2 || getWeekNum() == 4 || getWeekNum() == 6)) ||
                (getHour() > 13 && getHour() < 18 && (getWeekNum() == 3 || getWeekNum() == 5)))
            {
                sVEvent(grandpa_ingaddvor,1);
                addText(getStr(3));
            }
        }
        makeActBtn("go_izba", getStr(4));
        makeActBtn("go_sarai", getStr(5));
        makeActBtn("go_bana", getStr(6));
        makeActBtn("go_garden", getStr(7));
        if(gVEvent(meadow) > 0 && isDay() && getSnow() <= 0 && gVEvent(mira_guest) == 0)
            makeActBtn("go_meadow", getStr(8));
        if(isCloth())
            makeActBtn("go_village", getStr(9));
        if((gVEvent(fishers_nude) == 8 && getHour() >= 18 && getHour() <= 21) || (gVEvent(gadukino_nude) > 8 && getHour() >= 6 && getHour() <= 21))
        {
            startEvent(eGadukinoEvents, "gadriver_nude_end");
        }
        if(gVEvent(onlooker_man) == 1 && getHour() >= 6 && getHour() <= 21)
        {
            startEvent(eGadukinoEvents, "gadukino_onlooker_man");
        }
        mira_temp = getRandInt(1,5);
        if(mira_temp == 3 && getHour() >= 9 && getHour() <= 19 && gVQuest(miraQW) >= 15 && gVEvent(Mira_no) == 0 && gVEvent(mira_guest) == 0 && getSunWeather() >= 0 && gVEvent(mira_guestday) != gVStatus(daystart) && (gVEvent(mitkasextimes) < 13 || gVQuest(miragopQW) >= 10 || gVEvent(mirasex) > 1))
        {
            startEvent(eGrandParentEvents,"mira_courtyard");
        }
        if(getCloth(ClothType::Main) == nullptr)
        {
            startEvent(eGrandParentEvents,"courtyard_nude");
        }
    }
    if(action == "chickens")
    {
        startEvent(eGrandParentEvents,"chickens");
    }
    if(action == "Miroslava")
    {
        startEvent(eMiroslava);
    }
    if(action == "go_izba")
    {
        changeLoc(lgadhouse,5);
    }
    if(action == "go_sarai")
    {
        changeLoc(lgadsarai,5);
    }
    if(action == "go_bana")
    {
        changeLoc(lgadbana, 5);
    }
    if(action == "go_garden")
    {
        changeLoc(lgadgarden, 5);
    }
    if(action == "go_meadow")
    {
        changeLoc(lmeadow, 20);
    }
    if(action == "go_village")
    {
        changeLoc(lgadukino,5);
    }
}

void Gaddvor::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gaddvor");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gaddvor::actionHandler);
    addActBtn(btn);
}

QString Gaddvor::getStr(int id)
{
    QString ded;
    if(gVEvent(grandpa_notalk) == 0) ded = "<a href='grandpa'>дедушка</a>";
    else ded = "дедушка";
    QString str[10];
    str[0] = "Двор с садом, избой и хозпостройками огорожен изгородью.";
    str[1] = "По двору ходят <a href='chickens'>куры</a>";
    str[2] = "Во дворе, рядом с вами, стоит <a href='Miroslava'>Мира</a>.";
    str[3] = "Во дворе работает ваш " + ded;
    str[4] = "Идти в избу";
    str[5] = "Идти в сарай";
    str[6] = "Идти в баню";
    str[7] = "Идти на огород";
    str[8] = "Иди на поляну";
    str[9] = "Идти в деревню";
    return str[id];
}

QString Gaddvor::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/gaddvor/dvor.jpg";
    return med[id];
}
