#include "swamp.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

Swamp::Swamp(LocationHandler* ptr): Location(ptr) {}

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
    addActBtn(btn);
}

void Swamp::actionHandler(QString action)
{
    if (action == "swamp")
    {
        setImage(makeImage(media(0),isDay(),getMonth()));
        setDesc(str(0));
        if(isDay())
        {
            makeActBtn("to_forest",act(0));
            makeActBtn("gadforest",act(1));
            if(getMonth() >= 6 && getMonth() <= 9 && gVStatus(boletus) + gVStatus(bilberry) < 10 && gVEvent(swamp_day) != gVStatus(daystart))
                makeActBtn("search_food",act(2));
        }
        else
            makeActBtn("forest_road",act(1));
    }
    if(action == "to_forest")
    {
        sVStatus(swamp_clothes, 0);
        if(gVEvent(goforest) > getRandInt(1,100))
        {
            sVEvent(edge_forestday_current,4);
            changeLoc(lgadforest,30);
        }
        else
        {
            startEvent(eGadForestEvent,"gadforest_lost_start");
        }
    }
    if(action == "gadforest")
    {
        sVStatus(swamp_clothes, 0);
        sVEvent(hanters,0);
        sVEvent(edge_forestday_current,1);
        changeLoc(lgadforest,150);
    }
    if(action == "search_food")
    {
        incTime(30);
        sVEvent(swamp_day,gVStatus(daystart));
        if(gVEvent(goforest) < 20)
            uVEvent(goforest,getRandInt(0,1));
        new_bilbery = getRandInt(4,5);
        uVStatus(bilberry,new_bilbery);
        uVStatus(mood,5);
        startEvent(eGadForestEvent,"clothes1");
        setDesc(str(1));
        makeActBtn("swamp",act(3));
    }
    if(action == "forest_road")
    {
        sVStatus(swamp_clothes, 0);
        sVEvent(hanters,0);
        startEvent(eGadForestEvent,"forest_road");
    }
    if(action == "swamp_yard")
    {
        changeLoc(lswampyard,0);
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
