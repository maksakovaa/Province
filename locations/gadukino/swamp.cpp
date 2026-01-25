#include "swamp.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"
#include "../../game.h"

Swamp::Swamp(Game* ptr): root(ptr) {}

void Swamp::show(QString arg)
{
    actionHandler("swamp");
}

LocId Swamp::getLocId()
{
    return lswamp;
}

LocId Swamp::getLocIn()
{
    return lgadukino;
}

QString Swamp::getLocName()
{
    return "Болото";
}

LocId Swamp::getParId()
{
    return lgadforest;
}

bool Swamp::isParent()
{
    return true;
}

void Swamp::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"swamp");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Swamp::actionHandler);
    root->addActions(btn);
}

void Swamp::actionHandler(QString action)
{
    if (action == "swamp")
    {
        root->setImage(makeImage(media(0),root->isDay(),root->getMonth()));
        root->setText(str(0));
        if(root->isDay())
        {
            makeActBtn("to_forest",act(0));
            makeActBtn("gadforest",act(1));
            if(root->getMonth() >= 6 && root->getMonth() <= 9 && root->vStatus(boletus) + root->vStatus(bilberry) < 10 && root->vEvent(swamp_day) != root->vStatus(daystart))
                makeActBtn("search_food",act(2));
        }
        else
            makeActBtn("forest_road",act(1));
    }
    if(action == "to_forest")
    {
        root->vStatus(swamp_clothes) = 0;
        if(root->vEvent(goforest) > getRandInt(1,100))
        {
            root->vEvent(edge_forestday_current) = 4;
            root->changeLoc(lgadforest,30);
        }
        else
        {
            root->startEvent(eGadForestEvent,"gadforest_lost_start");
        }
    }
    if(action == "gadforest")
    {
        root->vStatus(swamp_clothes) = 0;
        root->vEvent(hanters) = 0;
        root->vEvent(edge_forestday_current) = 1;
        root->changeLoc(lgadforest,150);
    }
    if(action == "search_food")
    {
        root->incTime(30);
        root->vEvent(swamp_day) = root->vStatus(daystart);
        if(root->vEvent(goforest) < 20)
            root->vEvent(goforest) += getRandInt(0,1);
        new_bilbery = getRandInt(4,5);
        root->vStatus(bilberry) += new_bilbery;
        root->vStatus(mood) += 5;
        root->startEvent(eGadForestEvent,"clothes1");
        root->setText(str(1));
        makeActBtn("swamp",act(3));
    }
    if(action == "forest_road")
    {
        root->vStatus(swamp_clothes) = 0;
        root->vEvent(hanters) = 0;
        root->startEvent(eGadForestEvent,"forest_road");
    }
    if(action == "swamp_yard")
    {
        root->changeLoc(lswampyard,0);
    }
}

QString Swamp::str(int id)
{
    QString str[2];
    str[0] = "Лесное болото в которое опасно лезть днем, не то что ночью. Зато в лесу возле болота можно найти много грибов"
             " и ягод.<br>Немного в стороне видна сухая <a href='swamp_yard'>поляна</a> с ветхой избушкой - видимо это охотничий домик.";
    str[1] = "Вы в течение получаса бродили по лесу в поисках грибов или ягод и нашли " + intQStr(new_bilbery) + " кг ягод.";
    return str[id];
}

QString Swamp::act(int id)
{
    QString act[4];
    act[0] = "Войти в лес";
    act[1] = "Вернуться на окраину леса";
    act[2] = "Искать ягоды";
    act[3] = "Далее";
    return act[id];
}

QString Swamp::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/swamp/swamp.jpg";
    return med[id];
}
