#include "swampspring.h"
#include "../menu/qactbutton.h"
#include "../Functions.h"

SwampSpring::SwampSpring(LocationHandler* ptr): Location(ptr) {}

void SwampSpring::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("swampspring");
    else
        actionHandler(arg);
}

LocId SwampSpring::getLocId()
{
    return lswampspring;
}

LocId SwampSpring::getParId()
{
    return lswampyard;
}

LocId SwampSpring::getLocIn()
{
    return lgadukino;
}

QString SwampSpring::getLocName()
{
    return "Родник";
}

bool SwampSpring::isParent()
{
    return true;
}

void SwampSpring::actionHandler(QString action)
{
    if(action == "swampspring")
    {
        setImage(makeImage(media(0),isDay(),getMonth()));
        setDesc(str(0));
        makeActBtn("drink_water",act(0));
        if(gVEvent(bucket) < 10)
            makeActBtn("fill_bucket",act(2));
        makeActBtn("swamp_yard",act(3));
    }
    if(action == "drink_water")
    {
        incTime(5);
        if(gVStatus(water) >= 20)
        {
            setImage(media(1));
            setDesc(str(1));
        }
        else
        {
            uVStatus(water,20);
            sVStatus(cumLips,0);
            sVStatus(dirtylip,0);
            setImage(media(1));
            setDesc(str(2));
        }
        makeActBtn("swampspring",act(1));
    }
    if(action == "fill_bucket")
    {
        incTime(10);
        uVEvent(bucket,10);
        setImage(media(2));
        setDesc(str(3));
        makeActBtn("swampspring",act(1));
    }
    if(action == "swamp_yard")
    {
        changeLoc(lswampyard,5);
    }
}

void SwampSpring::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SwampSpring::actionHandler);
    addActBtn(btn);
}

QString SwampSpring::str(int id)
{
    QString str[20];
    str[0] = "Родник с чистой ключевой водой.";
    str[1] = "Вода в вас больше не лезет.";
    str[2] = "Вы с удовольствием напились родниковой воды.";
    str[3] = "Вы набрали воды в ведро.";
    return str[id];
}

QString SwampSpring::act(int id)
{
    QString act[4];
    act[0] = "Попить воды";
    act[1] = "Закончить";
    act[2] = "Набрать воды в ведро";
    act[3] = "Уйти";
    return act[id];
}

QString SwampSpring::media(int id)
{
    QString med[3];
    med[0] = "data/locations/gadukino/swamp/swampspring.jpg";
    med[1] = "data/actions/backwater/hands.jpg";
    med[2] = "data/locations/gadukino/swamp/vedro.jpg";
    return med[id];
}
