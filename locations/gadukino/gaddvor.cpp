#include "gaddvor.h"
#include "../../Functions.h"
#include "../../events/questenums.h"
#include "../../menu/buttons.h"
#include "../../game.h"
Gaddvor::Gaddvor(Game *ptr):  root(ptr) {}

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
        root->vEvent(grandpa_ingaddvor) =0;
        root->setImage(makeImage(media(0), root->isDay(), root->getMonth()));
        root->setText(getStr(0));
        if(root->isDay() && root->getMonth() >= 4 && root->getMonth() <= 10)
            root->addText(getStr(1));
        if(root->vEvent(mira_guest) == 1)
            root->addText(getStr(2));
        if(root->getMonth() > 5 && root->getMonth() < 9 && root->getSunWeather() >= 0 && root->vJob(graze_cow) == 0)
        {
            if((root->getHour() > 7 && root->getHour() < 13  && (root->getWeek() == 2 || root->getWeek() == 4 || root->getWeek() == 6)) ||
                (root->getHour() > 13 && root->getHour() < 18 && (root->getWeek() == 3 || root->getWeek() == 5)))
            {
                root->vEvent(grandpa_ingaddvor) = 1;
                root->addText(getStr(3));
            }
        }
        makeActBtn("go_izba", getStr(4));
        makeActBtn("go_sarai", getStr(5));
        makeActBtn("go_bana", getStr(6));
        makeActBtn("go_garden", getStr(7));
        if(root->vEvent(meadow) > 0 && root->isDay() && root->getSnow() <= 0 && root->vEvent(mira_guest) == 0)
            makeActBtn("go_meadow", getStr(8));
        if(root->isCloth())
            makeActBtn("go_village", getStr(9));
        if((root->vEvent(fishers_nude) == 8 && root->getHour() >= 18 && root->getHour() <= 21) || (root->vEvent(gadukino_nude) > 8 && root->getHour() >= 6 && root->getHour() <= 21))
        {
            root->startEvent(eGadukinoEvents, "gadriver_nude_end");
        }
        if(root->vEvent(onlooker_man) == 1 && root->getHour() >= 6 && root->getHour() <= 21)
        {
            root->startEvent(eGadukinoEvents, "gadukino_onlooker_man");
        }
        mira_temp = getRandInt(1,5);
        if(mira_temp == 3 && root->getHour() >= 9 && root->getHour() <= 19 && root->vQuest(miraQW) >= 15 && root->vEvent(Mira_no) == 0 && root->vEvent(mira_guest) == 0 && root->getSunWeather() >= 0 && root->vEvent(mira_guestday) != root->vStatus(daystart) && (root->vEvent(mitkasextimes) < 13 || root->vQuest(miragopQW) >= 10 || root->vEvent(mirasex) > 1))
        {
            root->startEvent(eGrandParentEvents,"mira_courtyard");
        }
        if(root->getCloth(ClothType::Main) == nullptr)
        {
            root->startEvent(eGrandParentEvents,"courtyard_nude");
        }
    }
    if(action == "chickens")
    {
        root->startEvent(eGrandParentEvents,"chickens");
    }
    if(action == "Miroslava")
    {
        root->startEvent(eMiroslava);
    }
    if(action == "go_izba")
    {
        root->changeLoc(lgadhouse,5);
    }
    if(action == "go_sarai")
    {
        root->changeLoc(lgadsarai,5);
    }
    if(action == "go_bana")
    {
        root->changeLoc(lgadbana, 5);
    }
    if(action == "go_garden")
    {
        root->changeLoc(lgadgarden, 5);
    }
    if(action == "go_meadow")
    {
        root->changeLoc(lmeadow, 20);
    }
    if(action == "go_village")
    {
        root->changeLoc(lgadukino,5);
    }
}

void Gaddvor::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gaddvor");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gaddvor::actionHandler);
    root->addActions(btn);
}

QString Gaddvor::getStr(int id)
{
    QString ded;
    if(root->vEvent(grandpa_notalk) == 0) ded = "<a href='grandpa'>дедушка</a>";
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
